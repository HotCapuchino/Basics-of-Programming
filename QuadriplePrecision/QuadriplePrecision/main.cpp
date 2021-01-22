#include <iostream>
#include <bitset>
#include "QuadriplePrecision.h"

using namespace std;

int main(void) {
	/*cout << "Hello World!\n";*/
	QuadriplePrecision num1 = QuadriplePrecision("12.25", 112, 16);
	cout << "num1:\n";
	num1.printScientificNotation();
	QuadriplePrecision num2 = QuadriplePrecision("4.25", 112, 16);
	cout << "\nnum2:\n";
	num2.printScientificNotation();
	/*num1.printBinaryRepresentation();
	num1.printScientificNotation();*/
	QuadriplePrecision num3 = num1 + num2;
	cout << "\nnum3:\n";
	num3.printScientificNotation();
	system("pause");
}
