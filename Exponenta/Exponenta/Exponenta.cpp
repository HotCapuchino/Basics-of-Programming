#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;
typedef unsigned long long int mll;
bool setNulls(mll* arr, int size);
void divide(mll* factorial, int size, int divider);
void add(mll* exp, mll* factorial, int size);
bool isZero(mll* factorial, int size);
void printExp(mll* exp, int size);
void checkExp();
const mll base = 1e2;
mll digits = 1e6;
int amount = digits / log10(base) + 1;

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
	/*printExp(exponenta, amount);*/
	/*checkExp();*/
	delete[] exponenta;
	delete[] factorial;
}

void divide(mll* factorial, int size, int divider) {
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

void add(mll* exponenta, mll* factorial, int size) {
	mll remained = 0;
	int i = size - 1;
	while (factorial[i] == 0)
	{
		i--;
	}
	for (i; i >= 0; i--)
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

bool setNulls(mll* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		try
		{
			arr[i] = 0;
		}
		catch (const exception&)
		{
			return false;
		}
	}
	return true;
}

bool isZero(mll* factorial, int size) {
	for (int i = 0; i < size; i++)
	{
		if (factorial[i] != 0) {
			return false;
		}
	}
	return true;
}

void printExp(mll* exponenta, int size) {
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

void checkExp() {
	ifstream exponenta;
	exponenta.open("exponenta.txt");
	if (!exponenta.is_open()) {
		cout << "Error occured while opening file\n";
	}
	ifstream example;
	example.open("example.txt");
	char c1 = 'l';
	char c2 = 'r';
	int counter = 0;
	while (c1 != '\0')
	{
		exponenta >> c1;
		example >> c2;
		cout << "Expected: " << c2 << ", got: " << c1 << endl;
		if (c1 != c2)
		{
			cout << counter;
			throw exception("error!");
		}
		counter++;
	}
}