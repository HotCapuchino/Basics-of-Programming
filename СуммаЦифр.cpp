#include "pch.h"
#include <iostream>


int summ(int m, int buf) {
	buf += m % 10;
	if (m < 10) {
		return buf;
	}
	else {
		summ(m / 10, buf);
	}

}

using namespace std;
int main()
{

    cout << "Enter number: \n";
	int m;
	cin >> m;
	if (m < 10) {
		cout << m;
	}
	else {
		cout << summ(m, 0);
	}
}

