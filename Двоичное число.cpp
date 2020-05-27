#include "pch.h"
#include <iostream>

using namespace std;
void toBinary(int num) {
	if (num <= 0) {
		return;
	}
	else {
		toBinary(num / 2);
		cout << num % 2;
	}
}

int main()
{
    cout << "Enter your number:\n";
	int num;
	cin >> num;
	toBinary(num);
}
