// КвадратМалевича.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<time.h>

using namespace std;
int main()
{
	srand(time(NULL));
    cout << "Enter n: "; 
	int n;
	cin >> n;
	int **matrix = new int*[n];
	int length = 1;
	int startJ = 0, startI = 0, finishJ = 0, finishI = 0;
	bool codeRed = false;
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 2;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0) 
			{
				startI = i;
				startJ = j;
				while (j <= n - 1 && i <= n - 1 && matrix[i][startJ] == 0 && matrix[startI][j] == 0 && matrix[i][j] == 0) 
				{									
					j++;						// если натыкаемся на ячейку равную 0, 
					i++;						// начинаем идти по i, j и диагонали, 
					finishI = i;				// пока ячейки матрицы равны 0
					finishJ = j;
					for (size_t k = startI; k < finishI; k++)
					{
						for (size_t h = startJ; h < finishJ; h++)
						{
							if (matrix[k][h] != 0) {
								codeRed = true;			// проходим полученную матрицу, дабы удостовериться, что все ее ячейки равны 0
								break;					// если натыкаемся на 1 - поднимаем специальный флаг
							}
						}
					}
					if (codeRed)
					{
						break;
					}
				}
				if (!codeRed)
				{
					if (length < finishI - startI)		
					{
						length = finishI - startI;		// если флаг не был поднят, сравниваем длину подматрицы с макисмальной длиной
					}
				}
				i = startI;				// возвращаем исходные i и j,
				j = startJ;				// чтобы не перескакивать элементы
				codeRed = false;
			}
		}
	}
	cout << "Max length of Malevich quad is: " << length;
	for (size_t i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
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
