// fifth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
bool possibleThreats(int queenX, int queenY, int kingX, int kingY) {
	if (queenX == kingX)
	{
		return true;
	}
	else if (queenY == kingY) 
	{
		return true;
	}
	else if (abs(queenX - kingX) == abs(queenY - kingY))
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int chess_desk[8][8];
	int kingX, kingY;
	bool areThereAnyThreats = false;
	int threatsCounter = 0;
	cout << "Fill in chess desk with the chess figures!\nInstruction: \n1 is for the king \n2 is for the enemy queen \n0 is empty space\n";
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			cin >> chess_desk[i][j];
			if (chess_desk[i][j] == 1)
			{
				kingX = i;
				kingY = j;
			}
		}
	}
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (chess_desk[i][j] == 2) 
			{
				if (possibleThreats(i, j, kingX, kingY))
				{
					areThereAnyThreats = true;
					chess_desk[i][j] = -1;
					threatsCounter++;
				}
			}
		}
	}
	if (areThereAnyThreats)
	{
		cout << "There is(are) " << threatsCounter << "threat(s) to the king \nAll threats are pointed as -1\n";
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				cout << chess_desk[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Nothing threaten to the king";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
