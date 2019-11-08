// Системы счисления.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
 
int poWwWer(int x, int power) {
	int result = 1;
	for (size_t i = 0; i < power; i++)
	{
		result *= x;
	}
	return result;
}

int toAnother(int digit, int x, int length) {
	int sum = 0;
	for (size_t i = 1; i <= length; i++)
	{
		sum += poWwWer(x, i - 1) * (digit % 10);
		digit = digit / 10;
	}
	return sum;
}

int main()
{
    cout << "Enter your expression without any spaces!\n";
	string expression;
	getline(cin, expression);
	string s1, s2 = "";
	int i = 0;
	int maxnumber = 0;
	while (expression[i] != '=')
	{
		s1 += expression[i];
		i++;
	}
	for (i += 1; i < expression.length(); i++)
	{
		s2 += expression[i];
		if ((expression[i] - '0') > maxnumber)
		{
			maxnumber = (expression[i] - '0');
		}
	}
	string part1, part2;
	i = 0;
	while (s1[i] != '*') {
		part1 += s1[i];
		if ((s1[i] - '0') > maxnumber)
		{
			maxnumber = (s1[i] - '0');
		}
		i++;
	}
	for (i += 1; i < s1.length(); i++)
	{
		 part2 += s1[i];
		 if ((s1[i] - '0') > maxnumber)
		 {
			 maxnumber = (s1[i] - '0');
		 }
	}
	int firstDigit, secondDigit, result;
	firstDigit = stoi(part1);
	secondDigit = stoi(part2);
	result = stoi(s2);
	i = maxnumber + 1;
	bool codeStop = false;
	while (!codeStop)
	{
		if (toAnother(firstDigit, i, part1.length()) * toAnother(secondDigit, i, part2.length()) == toAnother(result, i, s2.length()))
		{
			break;
		}
		i++;
		if (i > 65536)
		{
			cout << "I'm afraid i can't find such number system...";
			return 0;
		}
	}
	cout << "This expression is right for number system of " << i;
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
