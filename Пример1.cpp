#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double area(double R) {
	return M_PI * R * R;
}

int main()
{
	cout << "Enter radius of circle" << endl;
	double radius = 0;
	cin >> radius;
	double(*func)(double);
	func = area;
	cout << "Area of this citcle is: " << func(radius) << endl;
}
