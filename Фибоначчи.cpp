#include "pch.h"
#include <iostream>

int findFibonacci(int a) {
	if (a == 0) {
		return 0;
	}
	else if (a == 1 || a == 2)
	{
		return 1;
	}
	else {
		return findFibonacci(a - 1) + findFibonacci(a - 2);
	}
}

using namespace std;
int main()
{
    cout << "Enter the position of fibonacci number:\n";
	int n;
	cin >> n;
	cout << findFibonacci(n - 1);
}

