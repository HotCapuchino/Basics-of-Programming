#include "QuadriplePrecision.h"
#include <vector>


// приватный конструктор для создания числа при сложении
QuadriplePrecision::QuadriplePrecision(vector<short>& newMantisse, int newDegree) {
	mantisse.reserve(mantissePrecision);
	for (int i = newMantisse.size() - 1; i >= 0; i--) { // копируем новую мантиссу числа
		mantisse.push_back(newMantisse.at(i));
	}
	exponent.reserve(orderPrecision);
	degree = newDegree;
	createNumberOrder(degree); // вычисление порядка нового числа
	isFraction = true;
	insignificant_bit = 1;
}

// перевод целой части в двоичное представление
void QuadriplePrecision::convertDecimalToBinary() {
	short remain = 0;
	int startpoint = decimal_part_buffer.size() - 1; // тот индекс, с которого начинаем делить, (чтобы не делить нули)
	while (true) {
		for (int i = startpoint; i >= 0; i--) {
			short buffer = (remain * 10 + decimal_part_buffer.at(i)) / 2; // новое значение для ячейки
			remain = (remain * 10 + decimal_part_buffer.at(i)) % 2; // остаток 
			decimal_part_buffer.at(i) = buffer;
			if (buffer == 0) startpoint--; // если ячейка равна нулю, нам нужно сдвинуться на 1 ячейку вправо, (чтобы не делить ноль)
		}
		decimal_part_binary.push_back(remain);
		remain = 0;
		if (decimal_part_buffer.at(0) == 0) break;
	}
	degree = decimal_part_binary.size() - 1;
}

// перевод дробной части в двоичное представление
void QuadriplePrecision::convertFractionToBinary() {
	short remain = 0;
	for (int i = 0; i < mantissePrecision - degree; i++) { // так как под мантиссу всего 113 бит, 1 зарезервирован, вычитаем длину бинарного представления целой части, для достижения максимальной точности
		for (int j = 0; j < fraction_part_buffer.size(); j++) {
			short buffer = (fraction_part_buffer.at(j) * 2 + remain) % 10;
			remain = (fraction_part_buffer.at(j) * 2 + remain) / 10;
			fraction_part_buffer.at(j) = buffer;
		}
		fraction_part_binary.push_back(remain);
		remain = 0;
	}
}

// заполнение мантиссы числа
void QuadriplePrecision::createMantisse() {
	int counter = 0;
	for (int i = decimal_part_binary.size() - 2; i >= 0; i--) { // начинаем с предпоследнего индекса, потому что первый бит нормализованной мантиссы всегда равен 1
		mantisse.push_back(decimal_part_binary.at(i));
		counter++;
	}
	for (int i = 0; i < fraction_part_binary.size(); i++) {
		mantisse.push_back(fraction_part_binary.at(i));
		counter++;
	}
}

// заполнение порядка числа
void QuadriplePrecision::createNumberOrder(int degree) {
	int targetNumber = degree + BIAS_EXP;
	for (int i = 0; i < orderPrecision; i++) { // рассчитываем порядок записи, запись инвертирована
		exponent.push_back(targetNumber % 2);
		targetNumber /= 2;
	}
	exponent.push_back(sign);
}

// очистить порядок экспоненты
void QuadriplePrecision::clearNumberOrder() {
	exponent.clear();
}

// представление числа в scientific notation
void QuadriplePrecision::buildScientificNotation() {
	createMantisse();
	createNumberOrder(degree);
}

// разделение числа на дробную и целую часть
void QuadriplePrecision::parseInput(string inputNumber) {
	bool writeFraction = true;
	int end = verifyNumberSign(inputNumber) ? 1 : 0;
	for (int i = inputNumber.length() - 1; i >= end; i--) {
		if ((int)inputNumber[i] == 46 || (int)inputNumber[i] == 44) {
			writeFraction = false;
			continue;
		}
		if (writeFraction) {
			fraction_part.push_back(inputNumber[i] - '0');
			fraction_part_buffer.push_back(inputNumber[i] - '0');
		}
		else {
			decimal_part.push_back(inputNumber[i] - '0');
			decimal_part_buffer.push_back(inputNumber[i] - '0');
		}
	}
}

// проверка, является ли число дробью
void QuadriplePrecision::verifyNumberIsFraction(string inputNumber) {
	for (int i = 0; i < inputNumber.length(); i++) {
		if ((int)inputNumber[i] == 46 || (int)inputNumber[i] == 44) {
			isFraction = true;
			return;
		}
	}
	isFraction = false;
}

// проверка, был бы пользователем введен знак числа
bool QuadriplePrecision::verifyNumberSign(string inputNumber) {
	if ((int)inputNumber[0] == 45) {
		sign = 1;

		return true;
	}
	if ((int)inputNumber[0] == 43) {
		sign = 0;
		return true;
	}
	return false;
}

// вывод целой части
void QuadriplePrecision::printDecimalPart() {
	sign > 0 ? cout << "-" : cout << "";
	for (int i = decimal_part.size() - 1; i >= 0; i--) {
		cout << decimal_part.at(i);
	}
}

// вывод дробной части
void QuadriplePrecision::printFractionPart() {
	for (int i = fraction_part.size() - 1; i >= 0; i--) {
		cout << fraction_part.at(i);
	}
}

// вывод целой части в бинарном представлении
void QuadriplePrecision::printDecimalPartBinary() {
	for (int i = decimal_part_binary.size() - 1; i >= 0; i--) {
		cout << decimal_part_binary.at(i);
	}
}

// вывод дробной части в бинарном представлении
void QuadriplePrecision::printFractionPartBinary() {
	for (int i = 0; i < fraction_part_binary.size(); i++) {
		cout << fraction_part_binary.at(i);
	}
}

// нормализация двоинчого представления с новым основанием
void QuadriplePrecision::normalize(int newDegree) {
	mantisse.insert(mantisse.begin(), insignificant_bit); // смещаем первый бит мантиссы (он чаще всего равен 1)
	mantisse.pop_back(); // вытаскиваем последний бит, чтобы не превышать длину мантиссы
	for (int i = 0; i < newDegree - degree - 1; i++) { // смещаем мантиссу на необходимое количество бит, попутно заполняя смещаемые со старта биты нулями
		mantisse.insert(mantisse.begin(), 0);
		mantisse.pop_back();
	}
	degree = newDegree;
	clearNumberOrder();
	createNumberOrder(degree);
	insignificant_bit = 1;
}

// дефолтный конструктор
QuadriplePrecision::QuadriplePrecision(string number, int mantissePrecision, int orderPrecision) {
	this->mantissePrecision = mantissePrecision < 32 ? 32 : mantissePrecision;
	this->orderPrecision = orderPrecision < 7 ? 8 : orderPrecision + 1;
	BIAS_EXP = (int)pow(2, orderPrecision - 1) - 1;
	verifyNumberIsFraction(number);
	if (isFraction) {
		parseInput(number);
	}
	else {
		int end = verifyNumberSign(number) ? 1 : 0;
		for (int i = number.length() - 1; i >= end; i--) {
			decimal_part.push_back(number[i] - '0');
			decimal_part_buffer.push_back(number[i] - '0');
		}
	}
	insignificant_bit = 1;
	mantisse.reserve(mantissePrecision);
	exponent.reserve(orderPrecision);
	convertDecimalToBinary();
	convertFractionToBinary();
	buildScientificNotation();
};

// вывод числа в десятичной форме
void QuadriplePrecision::printNumber() {
	printDecimalPart();
	cout << ".";
	printFractionPart();
	cout << endl;
}

// вывод числа в бинарном представлении
void QuadriplePrecision::printBinaryRepresentation() {
	cout << "Binary representation: ";
	printDecimalPartBinary();
	cout << ".";
	printFractionPartBinary();
	cout << endl;
}

// вывод числа в scientific notation
void QuadriplePrecision::printScientificNotation() {
	int gap = 0;
	cout << "sign: " << exponent.at(exponent.size() - 1) << " ";
	cout << "order: ";
	for (int i = exponent.size() - 2; i >= 0; i--) {
		cout << exponent.at(i);
		gap++;
		if (gap == 8) {
			cout << " ";
			gap = 0;
		}
	}
	gap++;
	if (gap == 8) {
		cout << " ";
		gap = 0;
	}
	cout << " mantisse: " << insignificant_bit;
	for (int i = 0; i < mantissePrecision; i++) {
		cout << mantisse.at(i);
		gap++;
		if (gap == 8) {
			cout << " ";
			gap = 0;
		}
	}
}

QuadriplePrecision::~QuadriplePrecision() {}

QuadriplePrecision QuadriplePrecision::operator +(QuadriplePrecision& number) {
	short maxDegree = this->degree; // порядок для нового числа
	if (this->degree > number.degree) { // вычисление наибольшего порядка и приведение обоих чисел к нему
		number.normalize(this->degree);
		maxDegree = this->degree;
	}
	else if (this->degree < number.degree) {
		this->normalize(number.degree);
		maxDegree = number.degree;
	}
	int remain = 0;
	vector<short> newMantisse;
	newMantisse.reserve(mantissePrecision);
	short newDegree = maxDegree;
	for (int i = this->mantisse.size() - 1; i >= 0; i--) { // сложение двух мантисс и формирование мантиссы новой (инверсированной)
		newMantisse.push_back((this->mantisse.at(i) + number.mantisse.at(i) + remain) % 2);
		remain = (this->mantisse.at(i) + number.mantisse.at(i) + remain) / 2;
	}
	if ((this->insignificant_bit + number.insignificant_bit + remain) / 2) { // если 2 числа в сумме оказываются вне текущего диапазона, смещаем точку на 1 знак вправо, увеличивая порядок нового числа
		newMantisse.push_back((this->insignificant_bit + number.insignificant_bit + remain) % 2);
		newDegree++; // увеличение порядка на 1
	}
	return QuadriplePrecision(newMantisse, newDegree);
};
