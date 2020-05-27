#include "pch.h"
#include <iostream>

int findDivider(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b)
	{
		findDivider(a % b, b);
	}
	else {
		findDivider(a, b % a);
	}
}

using namespace std;
int main()
{
    cout << "Enter first number:\n";
	int a;
	cin >> a;
	cout << "Enter second number:\n";
	int b;
	cin >> b;
	cout << "The biggest general divider is: " << findDivider(a, b);
}

