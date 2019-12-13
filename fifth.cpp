#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
template <int row, int col>
void possibleThreats(int queenX, int queenY, int kingX, int kingY, int(&indexes)[row][col]) {
	int buffer;
	if (queenX == kingX)
	{
		if (queenY - kingY < indexes[2][0] && queenY > kingY)
		{
			indexes[0][0] = queenX;
			indexes[1][0] = queenY;
			indexes[2][0] = queenY - kingY;
		}
		else if (kingY - queenY < indexes[2][1] && kingY > queenY)
		{
			indexes[0][1] = queenX;
			indexes[1][1] = queenY;
			indexes[2][1] = kingY - queenY;
		}
	}
	else if (queenY == kingY)
	{
		if (queenX - kingX < indexes[2][2] && queenX > kingX)
		{
			indexes[0][2] = queenX;
			indexes[1][2] = queenY;
			indexes[2][2] = queenX - kingX;
		}
		else if (kingX - queenX < indexes[2][3] && kingX > queenX)
		{
			indexes[0][3] = queenX;
			indexes[1][3] = queenY;
			indexes[2][3] = queenX - kingX;
		}
	}
	else if (abs(queenX - kingX) == abs(queenY - kingY))
	{
		buffer = abs(kingX - queenX);
		if (queenX < kingX && queenY < kingY && buffer < indexes[2][4])
		{
			indexes[0][4] = queenX;
			indexes[1][4] = queenY;
			indexes[2][4] = buffer;
		}
		else if (queenX > kingX && queenY < kingY && buffer < indexes[2][5])
		{
			indexes[0][5] = queenX;
			indexes[1][5] = queenY;
			indexes[2][5] = buffer;
		}
		else if (queenX < kingX && queenY > kingY && buffer < indexes[2][6])
		{
			indexes[0][6] = queenX;
			indexes[1][6] = queenY;
			indexes[2][6] = buffer;
		}
		else if (queenX > kingX && queenY > kingY && buffer < indexes[2][7])
		{
			indexes[0][7] = queenX;
			indexes[1][7] = queenY;
			indexes[2][7] = buffer;
		}
	}
}

int main()
{
	srand(time(0));
	int chess_desk[8][8];
	int indexes[3][8];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			indexes[i][j] = 8;
		}
	}
	int kingX, kingY;
	bool isKingLocated = false;
	bool areThereAnyThreats = false;
	int threatsCounter = 0;
	int random;
	cout << "Instruction: \n1 is for the king \n2 is for the enemy queen \n0 is empty space\n";
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			chess_desk[i][j] = rand() % 3;
			if (chess_desk[i][j] == 1 && isKingLocated)
			{
				random = rand() - rand();
				random <= 0 ? chess_desk[i][j] += -1 : chess_desk[i][j] += 1;
			}
			else if (chess_desk[i][j] == 1 && !isKingLocated) {
				kingX = i;
				kingY = j;
				isKingLocated = true;
			}
			cout << chess_desk[i][j] << " ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (chess_desk[i][j] == 2) 
			{
				possibleThreats(i, j, kingX, kingY, indexes);
			}
		}
	}
	for (size_t i = 0; i < 8; i++)
	{
		if (indexes[2][i] != 8)
		{
			chess_desk[indexes[0][i]][indexes[1][i]] = -2;
			areThereAnyThreats = true;
			threatsCounter++;
		}
	}
	if (areThereAnyThreats)
	{
		cout << "There is(are) " << threatsCounter << " threat(s) to the king \nAll threats are pointed as -2\n";
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				if (i == kingX && j == kingY)
				{
					chess_desk[i][j] = 1;
				}
				cout << setw(2) << chess_desk[i][j] << " ";
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
