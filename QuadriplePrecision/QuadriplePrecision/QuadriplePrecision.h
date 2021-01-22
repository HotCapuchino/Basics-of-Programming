#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class QuadriplePrecision {
private:
	int BIAS_EXP;
	short sign = 0;
	vector<short> exponent; // инвертирован
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
	int mantissePrecision; // точность мантиссы в битах
	int orderPrecision; // точность порядка в битах

	QuadriplePrecision(vector<short>& newMantisse, int newDegree); // приватный конструктор для создания числа при сложении

	void convertDecimalToBinary(); // перевод целой части в двоичное представление

	void convertFractionToBinary(); // перевод дробной части в двоичное представление

	void createMantisse(); // заполнение мантиссы числа

	void createNumberOrder(int degree); // заполнение порядка числа
	 
	void clearNumberOrder(); // очистить порядок экспоненты

	void buildScientificNotation(); // представление числа в scientific notation

	void parseInput(string inputNumber); // разделение числа на дробную и целую часть

	void verifyNumberIsFraction(string inputNumber); // проверка, является ли число дробью

	bool verifyNumberSign(string inputNumber); // проверка, был бы пользователем введен знак числа

	void printDecimalPart(); // вывод целой части

	void printFractionPart(); // вывод дробной части

	void printDecimalPartBinary(); // вывод целой части в бинарном представлении

	void printFractionPartBinary(); // вывод дробной части в бинарном представлении

	void normalize(int newDegree); // нормализация двоинчого представления с новым основанием

public:
	QuadriplePrecision(string number, int mantissePrecision, int orderPrecision); // дефолтный конструктор

	void printNumber(); // вывод числа в десятичной форме

	void printBinaryRepresentation(); // вывод числа в бинарном представлении

	void printScientificNotation(); // вывод числа в scientific notation

	~QuadriplePrecision();

	QuadriplePrecision operator +(QuadriplePrecision& number);
};
