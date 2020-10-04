#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;
typedef unsigned long long mll;
bool setNulls(mll* arr, mll size);
void divide(mll* factorial, mll size, int divider);
void add(mll* exp, mll* factorial, mll size);
bool isZero(mll* factorial, mll size);
void printExp(mll* exp, mll size);
const mll base = 10e12;
mll digits = 10e6;
mll amount = digits / log10(base) + 1;

int main()
{
	mll *exponenta = new mll[amount];
	mll *factorial = new mll[amount];
	setNulls(exponenta, amount);
	setNulls(factorial, amount);
	exponenta[0] = 1;
	factorial[0] = 1;
	int i = 1;
	time_t start_time, end_time;
	time(&start_time);
	while (!isZero(factorial, amount))
	{
		divide(factorial, amount, i);
		add(exponenta, factorial, amount);
		i++;
	}
	time(&end_time);
	time_t inGeneral = end_time - start_time;
	printf("General Time: %ld seconds. ", inGeneral);
	printExp(exponenta, amount);
	delete[] exponenta;
	delete[] factorial;
}

void divide(mll* factorial, mll size, int divider) {
	mll result = 0;
	mll buffer = 0;
	int counter = 0;
	while (factorial[counter] == 0)
	{
		counter++;
	}
	for (counter; counter < size; counter++)
	{
		buffer = factorial[counter] + result * base;
		factorial[counter] = buffer / divider;
		result = buffer - factorial[counter] * divider;
	}
}

void add(mll* exponenta, mll* factorial, mll size) {
	mll remained = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		exponenta[i] += factorial[i] + remained;
		if (exponenta[i] > base) {
			exponenta[i] -= base;
			remained = 1;
		}
		else {
			remained = 0;
		}
	}
}

bool setNulls(mll* arr, mll size) {
	for (int i = 0; i < size; i++)
	{
		try
		{
			arr[i] = 0;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	return true;
}

bool isZero(mll* factorial, mll size) {
	for (int i = 0; i < size; i++)
	{
		if (factorial[i]) {
			return false;
		}
	}
	return true;
}

void printExp(mll* exponenta, mll size) {
	ofstream fout;
	fout.open("exponenta.txt");
	fout << exponenta[0] << ".";
	int cell_size = log10(base);
	for (int i = 1; i < size; i++)
	{
		fout << setfill('0') << setw(cell_size) << exponenta[i];
	}
	fout.close();
}