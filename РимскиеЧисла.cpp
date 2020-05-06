#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Dictionary
{
	string roman_num_capital[14] = { "0", "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	int arabic_num[15] = { 0, 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000, 10000 };

	int deg(int y, int x = 10) {
		int result = 1;
		for (size_t i = 0; i < y; i++)
		{
			result *= x;
		}
		return result;
	}

	string getRoman(int num) {
		string whole_number = "";
		bool found = false;
		for (size_t i = 4; i > 0; i--)
		{
			int buf = num % deg(i) / deg(i - 1);
			for (size_t j = 0; j < 14; j++)
			{
				int cmpr_variable = num - num % deg(i - 1);
				if (cmpr_variable == arabic_num[j]) {
					found = true;
					num %= deg(i - 1);
					whole_number += roman_num_capital[j];
				}
			}
			if (!found)
			{
				num %= deg(i - 1);
				int number = buf * deg(i - 1);
				while (number > 0)
				{
					int min_difference = 10000;
					for (size_t k = 0; k < 15; k++) 
					{
						if (number - arabic_num[k] < 0) {
							whole_number += roman_num_capital[k - 1];
							number -= arabic_num[k - 1];
							break;
						}
						min_difference = number - arabic_num[k];
					}
				}
			}
			found = false;
		}
		return whole_number;
	}

	int getArabic(string num) {
		char lil_string[2];
		int whole_number = 0;
		bool found = false;
		for (int i = num.length() - 1; i > -1; i -= 2)
		{
			if (i == 0)
			{
				lil_string[0] = '0';
			}
			else {
				lil_string[0] = num[i - 1];
			}
			lil_string[1] = num[i];
			string s1(lil_string, sizeof(lil_string));
			for (size_t j = 0; j < 14; j++)
			{
				if (s1 == roman_num_capital[j]) {
					whole_number += arabic_num[j];
					found = true;
					break;
				}
			}
			if (!found)
			{
				string s2 = "";
				s2.push_back(lil_string[0]);
				string s3 = "";
				s3.push_back(lil_string[1]);
				for (size_t j = 0; j < 14; j++)
				{
					if (s2 == roman_num_capital[j])
					{
						whole_number += arabic_num[j];
					}
					if (s3 == roman_num_capital[j])
					{
						whole_number += arabic_num[j];
					}
				}
			}
			found = false;
		}
		return whole_number;
	}

};

string fromArabicToRoman(string num) {
	string whole_number = "";
	if (stoi(num) > 3999 || stoi(num) < 1)
	{
		return "W";
	}
	Dictionary dict = Dictionary();
	whole_number += dict.getRoman(stoi(num));
	return whole_number;
}
int checkFormat(char ch) {
	char possible_symbols[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	for (size_t i = 0; i < 7; i++)
	{
		if (ch == possible_symbols[i]) {
			return i + 1;
		}
	}
	return -1;
}
int fromRomanToArabic(string num) {
	int code[4] = { -1, -1, -1, -1 };
	int whole_number = 0;
	Dictionary dict = Dictionary();
	for (size_t i = 0; i < num.length(); i++)
	{
		if (checkFormat(num[i]) == -1) {
			return -1;
		}
		code[i % 4] = checkFormat(num[i]);
		if (code[0] == code[1] && code[1] == code[2] && code[2] == code[3])
		{
			return -1;
		}
	}
	return dict.getArabic(num);
}

int main()
{
    cout << "Enter arabic or roman number:\n"; 
	cout << "Pls, for Roman nubers use onle capital numbers, my program isn't perfect\n";
	string number = "";
	cin >> number;
	bool isNum = true;
	try
	{
		stoi(number);
	}
	catch (const invalid_argument&)
	{
		isNum = false;
	}
	if (!isNum)
	{
		int digit = fromRomanToArabic(number);
		digit == -1 ? cout << "Wrong Arabic number!" : cout <<digit;
	}
	else {
		string s1 = fromArabicToRoman(number);
		if (s1 == "W") 
		{
			cout << "Wrong Arabic number!";
		}
		else
		{
			for (size_t i = 0; i < s1.length(); i++)
			{
				if (s1[i] != '0')
				{
					cout << s1[i];
				}
			}
		}
	}
}
