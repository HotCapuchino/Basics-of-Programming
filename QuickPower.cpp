#include "pch.h"
#include <iostream>

float quickPower(float num, int power) {
	if (power == 0) {
		return 1;
	}
	else if (power % 2 != 0)
	{
		return (num * quickPower(num, power - 1));
	}
	else {
		return quickPower(num * num, power / 2);
	}
}

using namespace std;
int main()
{
   cout << "Enter number:\n";
   float x;
   cin >> x;
   cout << "Enter the power:\n";
   int n;
   cin >> n;
   if (n <= 0 && x == 0) {
	   cout << "Wrong data";
	   return -1;
   }
   cout << quickPower(x, n);
}
