// WinningStrategy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;
    cout << "Enter the amount of the sticks!\n";
	int amount;
	cin >> amount;
	int userTurn = 0, computerTurn = 0, j = 0;
	if (amount % 6 == 0) {
		cout << "Computer turn" << endl;
		cout << "Current total amount of sticks: " << amount << endl;
		computerTurn = 5 - userTurn;
		amount -= computerTurn;
		cout << "Sticks left: " << amount << endl;
	}
	else {
		j = amount / 6;
		cout << "Computer turn" << endl;
		cout << "Current total amount of sticks: " << amount << endl;
		computerTurn = amount - j * 6;
		amount -= computerTurn;
		j = 0;
		cout << "Sticks left: " << amount << endl;
	}
	int i = 2;
	while (amount > 0)
	{
		if (i % 2 != 0) 
		{
			cout << "Computer turn" << endl;
			cout << "Current total amount of sticks: " << amount << endl;
			if (amount % 6 == 0)
			{
				computerTurn = 6 - userTurn;
				amount -= computerTurn;
			}
			else
			{
				int j = amount / 6;
				computerTurn = amount - j * 6;
				amount -= computerTurn;
				j = 0;
			}
			cout << "Sticks left: " << amount << endl;
		}
		else
		{
			cout << "Current total amount of sticks: " << amount << endl;
			cout << "Your Turn! Enter the amount of sticks you want to remove, but remember that you can't remove up to 5 sticks per turn: ";
			cin >> userTurn;
			amount -= userTurn;
			cout << "Sticks left: " << amount << endl;
		}
		i++;
	}
	if ((i - 1) % 2 != 0)
	{
		cout << "Computer won!";
	}
	else
	{
		cout << "User won!";
	}
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
