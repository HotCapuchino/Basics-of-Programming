#include "pch.h"
#include <iostream>

using namespace std;
float my_plus(float, float);

int main()
{
    cout << "Enter the first number: ";
	float x = 0;
	cin >> x;
	cout << "Enter the second number: ";
	float y = 0;
	cin >> y;
	float(*func)(float, float);
	cout << "The sum is equal to: " << my_plus(x, y) << endl;
	func = my_plus;
	cout << "The sum is equal to: " << func(x, y) << endl;
}

float my_plus(float a, float b) {
	return a + b;
}