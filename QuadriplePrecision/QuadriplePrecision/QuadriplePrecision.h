#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class QuadriplePrecision {
private:
	const int BIAS_EXP = 16383;
	short sign = 0;
	vector<short> exp; // ������������
	short insignificant_bit;
	vector<short> mantisse; // �� �������������
	vector<short> decimal_part; // ������������
	vector<short> decimal_part_buffer; // ������������
	vector<short> fraction_part; // ������������
	vector<short> fraction_part_buffer; // ������������
	vector<short> decimal_part_binary; // �����������
	vector<short> fraction_part_binary; // �� ������������
	bool isFraction;
	int degree;

	// ��������� ����������� ��� �������� ����� ��� ��������
	QuadriplePrecision(vector<short>& newMantisse, int newDegree) {
		mantisse.reserve(112);
		for (int i = 111; i >= 0; i--) { // �������� ����� �������� �����
			mantisse.push_back(newMantisse.at(i)); 
		}
		exp.reserve(16);
		degree = newDegree;
		createNumberOrder(degree); // ���������� ������� ������ �����
		isFraction = true;
		insignificant_bit = 1;
	}

	// ������� ����� ����� � �������� �������������
	void convertDecimalToBinary() {
		short remain = 0;
		int startpoint = decimal_part_buffer.size() - 1; // ��� ������, � �������� �������� ������, (����� �� ������ ����)
		while (true) {
			for (int i = startpoint; i >= 0; i--) {
				short buffer = (remain * 10 + decimal_part_buffer.at(i)) / 2; // ����� �������� ��� ������
				remain = (remain * 10 + decimal_part_buffer.at(i)) % 2; // ������� 
				decimal_part_buffer.at(i) = buffer;
				if (buffer == 0) startpoint--; // ���� ������ ����� ����, ��� ����� ���������� �� 1 ������ ������, (����� �� ������ ����)
			}
			decimal_part_binary.push_back(remain);
			remain = 0;
			if (decimal_part_buffer.at(0) == 0) break;
		}
		degree = decimal_part_binary.size() - 1;
	}

	// ������� ������� ����� � �������� �������������
	void convertFractionToBinary() {
		short remain = 0;
		for (int i = 0; i < 112 - degree; i++) { // ��� ��� ��� �������� ����� 113 ���, 1 ��������������, �������� ����� ��������� ������������� ����� �����, ��� ���������� ������������ ��������
			for (int j = 0; j < fraction_part_buffer.size(); j++) {
				short buffer = (fraction_part_buffer.at(j) * 2 + remain) % 10;
				remain = (fraction_part_buffer.at(j) * 2 + remain) / 10;
				fraction_part_buffer.at(j) = buffer;
			}
			fraction_part_binary.push_back(remain);
			remain = 0;
		}
	}

	// ���������� �������� �����
	void createMantisse() {
		int counter = 0;
		for (int i = decimal_part_binary.size() - 2; i >= 0; i--) { // �������� � �������������� �������, ������ ��� ������ ��� ��������������� �������� ������ ����� 1
			mantisse.push_back(decimal_part_binary.at(i));
			counter++;
		}
		for (int i = 0; i < fraction_part_binary.size(); i++) {
			mantisse.push_back(fraction_part_binary.at(i));
			counter++;
		}
	}

	// ���������� ������� �����
	void createNumberOrder(int degree) {
		int targetNumber = degree + BIAS_EXP; 
		for (int i = 0; i < 15; i++) { // ������������ ������� ������, ������ �������������
			exp.push_back(targetNumber % 2);
			targetNumber /= 2;
		}
		exp.push_back(sign);
	}

	void clearNumberOrder() {
		exp.clear();
	}

	// ������������� ����� � scientific notation
	void buildScientificNotation() {
		createMantisse();
		createNumberOrder(degree);
	}

	// ���������� ����� �� ������� � ����� �����
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

	// ��������, �������� �� ����� ������
	void verifyNumberIsFraction(string inputNumber) {
		for (int i = 0; i < inputNumber.length(); i++) {
			if ((int)inputNumber[i] == 46 || (int)inputNumber[i] == 44) {
				isFraction = true;
				return;
			}
		}
		isFraction = false;
	}
	
	// ��������, ��� �� ������������� ������ ���� �����
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

	// ����� ����� �����
	void printDecimalPart() {
		sign > 0 ? cout << "-" : cout << "";
		for (int i = decimal_part.size() - 1; i >= 0; i--) {
			cout << decimal_part.at(i);
		}
	}

	// ����� ������� �����
	void printFractionPart() {
		for (int i = fraction_part.size() - 1; i >= 0; i--) {
			cout << fraction_part.at(i);
		}
	}

	// ����� ����� ����� � �������� �������������
	void printDecimalPartBinary() {
		for (int i = decimal_part_binary.size() - 1; i >= 0; i--) {
			cout << decimal_part_binary.at(i);
		}
	}

	// ����� ������� ����� � �������� �������������
	void printFractionPartBinary() {
		for (int i = 0; i < fraction_part_binary.size(); i++) {
			cout << fraction_part_binary.at(i);
		}
	}

	// ������������ ��������� ������������� � ����� ����������
	void normalize(int newDegree) {
		mantisse.insert(mantisse.begin(), insignificant_bit); // ������� ������ ��� �������� (�� ���� ����� ����� 1)
		mantisse.pop_back(); // ����������� ��������� ���, ����� �� ��������� ����� ��������
		for (int i = 0; i < newDegree - degree - 1; i++) { // ������� �������� �� ����������� ���������� ���, ������� �������� ��������� �� ������ ���� ������
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

	// ����� ����� � ���������� �����
	void printNumber() {
		printDecimalPart();
		cout << ".";
		printFractionPart();
		cout << endl;
	}

	// ����� ����� � �������� �������������
	void printBinaryRepresentation() {
		cout << "Binary representation: ";
		printDecimalPartBinary();
		cout << ".";
		printFractionPartBinary();
		cout << endl;
	}

	// ����� ����� � scientific notation
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
		short maxDegree = this->degree; // ������� ��� ������ �����
		if (this->degree > number.degree) { // ���������� ����������� ������� � ���������� ����� ����� � ����
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
		for (int i = this->mantisse.size() - 1; i >= 0; i--) { // �������� ���� ������� � ������������ �������� ����� (���������������)
			newMantisse.push_back((this->mantisse.at(i) + number.mantisse.at(i) + remain) % 2);
			remain = (this->mantisse.at(i) + number.mantisse.at(i) + remain) / 2;
		}
		if ((this->insignificant_bit + number.insignificant_bit + remain) / 2) { // ���� 2 ����� � ����� ����������� ��� �������� ���������, ������� ����� �� 1 ���� ������, ���������� ������� ������ �����
			newMantisse.push_back((this->insignificant_bit + number.insignificant_bit + remain) % 2);
			newDegree++; // ���������� ������� �� 1
		}
		return QuadriplePrecision(newMantisse, newDegree);
	};
	/*QuadriplePrecision operator -(QuadriplePrecision& number);*/
};