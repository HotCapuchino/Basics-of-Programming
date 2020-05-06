#include "pch.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void check(char *a, char *b, int(*cmp)(const char *, const char *));

int main()
{
	char s1[80];
	char s2[20];
	int(*p)(const char*, const char*);
	p = strcmp;
    cout << "Enter the first string:\n";
	cin >> s1;
	cout << "Enter the second string:\n";
	cin >> s2;
	check(s1, s2, p);
}

void check(char *a, char *b, int(*cmp)(const char *, const char *)) {
	cout << "Checking if the strings are the same: " << endl;
	if (!(*cmp)(a, b))
	{
		cout << "Equal!";
	}
	else {
		cout << "Not equal!";
	}
}