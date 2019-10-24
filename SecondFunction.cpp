﻿// SecondFunction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	using namespace std;
	cout << "Function y = tan(x)!\n";
	int sum = 0, multiply = 1;
	float i;
	int iterator = 0;
	int codes[101];
	double degree;
	for (i = -5; i <= 5; i += 0.1)
	{
		degree = i * 180 / M_PI;
		if (tan(degree) == tan(-degree))
		{
			codes[iterator] = 0;
		}
		else if (tan(-degree) == -1 * tan(degree))
		{
			codes[iterator] = 1;
		}
		else if (tan(degree) != -1 * tan(degree))
		{
			codes[iterator] = iterator;
		}
		iterator++;
	}
	for (size_t i = 0; i < 101; i++)
	{
		sum = sum + codes[i];
		multiply = multiply + codes[i];
	}
	if (sum != 0)
	{
		if (multiply > 1)
		{
			cout << "Function is ordinary!";
		}
		else if (multiply == 1) {
			cout << "Function is odd!";
		}
	}
	else
	{
		cout << "Function is even!";
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
