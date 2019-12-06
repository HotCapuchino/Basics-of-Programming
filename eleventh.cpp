// eleventh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int main()
{
	using namespace std;
	srand(time(0));
    cout << "Enter n: ";
	int n;
	cin >> n;
	cout << "Enter m: ";
	int m;
	cin >> m;
	int **my_matrix = new int*[m];
	int *repeated = new int[n];
	cout << "Before: \n";
	bool repeatedly = false;
	for (size_t i = 0; i < m; i++)
	{
		my_matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			my_matrix[i][j] = rand() % 5 + 1;
			cout << my_matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (size_t i = 0; i < n; i++)
	{
		repeated[i] = my_matrix[0][i];
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++) {
			if (repeated[i] == repeated[j] && repeated[i] != 0) 
			{
				repeated[j] = 0;
			}
		}
	}
	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				if (repeated[j] == my_matrix[i][k]) {
					repeatedly = true;
					break;
				}
			}
			repeatedly == false ? repeated[j] = 0 : repeatedly = false;
		}
	}
	cout << "Repeated numbers: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (repeated[i] != 0) {
			cout << repeated[i] << " ";
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		delete[] my_matrix[i];
	}
	delete[] my_matrix;
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
