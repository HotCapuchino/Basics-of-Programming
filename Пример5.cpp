#include "pch.h"
#include <iostream>
using namespace std;

void test1() {
	cout << "Executing test 1..." << endl;
}

void test2() {
	cout << "Executing test 2..." << endl;
}

void test3() {
	cout << "Executing test 3..." << endl;
}

void(*tests[])(void) {
	test1, test2, test3
};

int main()
{
	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		tests[i]();
	}
}

