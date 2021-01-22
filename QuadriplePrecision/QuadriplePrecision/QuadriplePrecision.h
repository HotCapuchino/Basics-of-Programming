#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class QuadriplePrecision {
private:
	const int BIAS_EXP = 16383;
	short sign = 0;
	vector<short> exp; // инвертирован
	short insignificant_bit;
	vector<short> mantisse; // не инвертирована
	vector<short> decimal_part; // инвертирован
	vector<short> decimal_part_buffer; // инвертирован
	vector<short> fraction_part; // инвертирован
	vector<short> fraction_part_buffer; // инвертирован
	vector<short> decimal_part_binary; // инвертрован
	vector<short> fraction_part_binary; // не инвертирован
	bool isFraction;
	int degree;

	// приватный конструктор для создания числа при сложении
	QuadriplePrecision(vector<short>& newMantisse, int newDegree) {
		mantisse.reserve(112);
		for (int i = 111; i >= 0; i--) { // копируем новую мантиссу числа
			mantisse.push_back(newMantisse.at(i)); 
		}
		exp.reserve(16);
		degree = newDegree;
		createNumberOrder(degree); // вычисление порядка нового числа
		isFraction = true;
		insignificant_bit = 1;
	}

	// перевод целой части в двоичное представление
	void convertDecimalToBinary() {
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
	void convertFractionToBinary() {
		short remain = 0;
		for (int i = 0; i < 112 - degree; i++) { // так как под мантиссу всего 113 бит, 1 зарезервирован, вычитаем длину бинарного представления целой части, для достижения максимальной точности
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
	void createMantisse() {
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
	void createNumberOrder(int degree) {
		int targetNumber = degree + BIAS_EXP; 
		for (int i = 0; i < 15; i++) { // рассчитываем порядок записи, запись инвертирована
			exp.push_back(targetNumber % 2);
			targetNumber /= 2;
		}
		exp.push_back(sign);
	}

	void clearNumberOrder() {
		exp.clear();
	}

	// представление числа в scientific notation
	void buildScientificNotation() {
		createMantisse();
		createNumberOrder(degree);
	}

	// разделение числа на дробную и целую часть
	void parseInput(string inputNumber) {
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
	void verifyNumberIsFraction(string inputNumber) {
		for (int i = 0; i < inputNumber.length(); i++) {
			if ((int)inputNumber[i] == 46 || (int)inputNumber[i] == 44) {
				isFraction = true;
				return;
			}
		}
		isFraction = false;
	}
	
	// проверка, был бы пользователем введен знак числа
	bool verifyNumberSign(string inputNumber) {
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
	void printDecimalPart() {
		sign > 0 ? cout << "-" : cout << "";
		for (int i = decimal_part.size() - 1; i >= 0; i--) {
			cout << decimal_part.at(i);
		}
	}

	// вывод дробной части
	void printFractionPart() {
		for (int i = fraction_part.size() - 1; i >= 0; i--) {
			cout << fraction_part.at(i);
		}
	}

	// вывод целой части в бинарном представлении
	void printDecimalPartBinary() {
		for (int i = decimal_part_binary.size() - 1; i >= 0; i--) {
			cout << decimal_part_binary.at(i);
		}
	}

	// вывод дробной части в бинарном представлении
	void printFractionPartBinary() {
		for (int i = 0; i < fraction_part_binary.size(); i++) {
			cout << fraction_part_binary.at(i);
		}
	}

	// нормализация двоинчого представления с новым основанием
	void normalize(int newDegree) {
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

public:
	QuadriplePrecision(string number) {
		verifyNumberIsFraction(number);
		if (isFraction) {
			parseInput(number);
		} else {
			int end = verifyNumberSign(number) ? 1 : 0;
			for (int i = number.length() - 1; i >= end; i--) {
				decimal_part.push_back(number[i] - '0');
				decimal_part_buffer.push_back(number[i] - '0');
			}
		}
		insignificant_bit = 1;
		mantisse.reserve(112);
		exp.reserve(16);
		convertDecimalToBinary();
		convertFractionToBinary();
		buildScientificNotation();
	};

	// вывод числа в десятичной форме
	void printNumber() {
		printDecimalPart();
		cout << ".";
		printFractionPart();
		cout << endl;
	}

	// вывод числа в бинарном представлении
	void printBinaryRepresentation() {
		cout << "Binary representation: ";
		printDecimalPartBinary();
		cout << ".";
		printFractionPartBinary();
		cout << endl;
	}

	// вывод числа в scientific notation
	void printScientificNotation() {
		int gap = 0;
		cout << "sign: " << exp.at(exp.size() - 1) << " ";
		cout << "order: ";
		for (int i = exp.size() - 2; i >= 0; i--) {
			cout << exp.at(i);
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
		for (int i = 0; i < 112; i++) {
			cout << mantisse.at(i);
			gap++;
			if (gap == 8) {
				cout << " ";
				gap = 0;
			}
		}
	}

	~QuadriplePrecision() {
	
	};
	QuadriplePrecision operator +(QuadriplePrecision& number) {
		short maxDegree = this->degree; // порядок для нового числа
		if (this->degree > number.degree) { // вычисление наибольшего порядка и приведение обоих чисел к нему
			number.normalize(this->degree); 
			maxDegree = this->degree;
		} else if (this->degree < number.degree) {
			this->normalize(number.degree);
			maxDegree = number.degree;
		} 
		int remain = 0;
		vector<short> newMantisse;
		newMantisse.reserve(112);
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
	/*QuadriplePrecision operator -(QuadriplePrecision& number);*/
};