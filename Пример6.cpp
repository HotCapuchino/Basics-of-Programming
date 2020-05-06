#include "pch.h"
#include <iostream>
#define ERROR_DIV_BY_ZERO -2

using namespace std;

int calculate(int op1, int op2, int(*func)(int, int)) {
	return func(op1, op2);
}

int summ(int op1, int op2) { return op1 + op2; }
int diff(int op1, int op2) { return op1 - op2; }
int mult(int op1, int op2) { return op1 * op2; }
int divd(int op1, int op2) { 
	if (!op2) {
		exit(ERROR_DIV_BY_ZERO);
	}
	return op1 / op2; 
}
int bals(int op1, int op2) { return op1 % op2; }
int fastpow(int op1, int op2) {
	if (!op2) {
		return 1;
	}
	if (op2 % 2)
	{
		return op1 * fastpow(op1, op2 - 1);
	}
	else {
		return fastpow(op1*op1, op2 / 2);
	}
}

int(*foper[])(int, int) = { summ, diff, mult, divd, bals, fastpow };


int main()
{
	char coper[] = { '+', '-', '*', '/', '%', '^' };
	int noper = sizeof(coper) / sizeof(coper[0]);
	do
	{
		char buff[120];
		char *str = buff;
		char *endptr;
		char oper;
		cout << "statement for calculating (<st1><sybmbol><st2>): " << flush;
		cin >> buff;
		int op1, op2;
		op1 = strtod(str, &endptr);
		oper = *endptr++;
		op2 = strtod(str = endptr, &endptr);
		int i;
		for (i = 0; i < noper; i++)
		{
			if (oper = coper[i]) {
				cout << op1 << ' ' << oper << ' ' << op2 << " = " << calculate(op1, op2, foper[i]) << endl;
				break;
			}
			if (i == noper)
			{
				cout << "Incorrect symbol!" << oper << endl;
			}
		}
	} while (true); 
}
