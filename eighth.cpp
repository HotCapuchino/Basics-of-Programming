﻿// eighth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;
    cout << "Enter n: ";
	int n;
	cin >> n;
	int min = INT_MAX;
	cout << "Fill in the array:\n";
	int *my_array = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> my_array[i];
		if (my_array[i] >= min)
		{
			my_array[i] = min;
		}
		else
		{
			min = my_array[i];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << my_array[i] << " ";
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
