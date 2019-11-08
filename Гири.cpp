// Гири.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;
	cout << "Enter the massa!" << endl;
	int massa;
	cin >> massa;
	const int m1 = 1;
	const int m2 = 2;
	const int m5 = 5;
	int degree = 1;
	int iterator = 0;
	while (massa > m1 * degree) {
		degree = degree * 10;
	}
	degree = degree / 10;
	while (massa > 0) {
		if (massa < m1 * degree) {
			degree = degree / 10;
		}
		if (m5 * degree <= massa) {
			massa = massa - m5 * degree;
			cout << "Weight " << m5 * degree << endl;
			iterator++;
		}
		else if (m2 * degree <= massa) {
			massa = massa - m2 * degree;
			cout << "Weight " << m2 * degree << endl;
			iterator++;
		}
		else if (m1 * degree <= massa) {
			massa = massa - m1 * degree;
			cout << "Weight " << m1 * degree << endl;
			iterator++;
		}
	}
	cout << "Amount of weights is " << iterator;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
