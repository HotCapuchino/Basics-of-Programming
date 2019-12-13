// twelfth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int main()
{
	srand(time(0));
	using namespace std;
    cout << "Enter n: ";
	int n;
	cin >> n;
	cout << "Enter m: ";
	int m;
	cin >> m;
	int *string_massive = new int[n];
	int **matrix = new int*[m];
	short *repeated = new short[n];
	cout << "Matrix: \n";
	for (size_t i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			if (i == 0) {
				repeated[j] = 0;
				string_massive[j] = rand() % 10 + 1;
			}
			matrix[i][j] = rand() % 10 + 1;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Array B: \n";
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (string_massive[i] == string_massive[j] && string_massive[i] != 0) { //избавимся от повторений в массиве В(n)
				string_massive[j] = 0;
			}
		}
		cout << string_massive[i] << " ";
	}
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				if (string_massive[j] == matrix[i][k])
				{
					repeated[j]++;
				}
			}
		}
	}
	cout << "\nRepeated numbers: ";
	for (size_t i = 0; i < n; i++)
	{
		if (repeated[i] > 1) {
			cout << string_massive[i] << ", ";
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] string_massive;
	delete[] repeated;
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
