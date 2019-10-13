// diamond.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

int main()
{
	using namespace std;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите высоту ромба\n";
	int firstDiagonal;
	cin >> firstDiagonal;
	int height = firstDiagonal / 2;
	cout << "Введите ширину ромба\n";
	int secondDiagonal;
	cin >> secondDiagonal;
	int width = secondDiagonal / 2;
	cout << "Введите координуту x точки\n";
	int x;
	cin >> x;
	x < 0 ? x = x * -1 : x;
	cout << "Введите координуту y точки\n";
	int y;
	cin >> y;
	y < 0 ? y = y * -1 : y;
	int centerX1 = (x / width) * width;
	int centerY1 = (y / height + 1) * height;
	int centerX2 = (x / width + 1) * width;
	int centerY2 = (y / height) * height;
	if (x % width == 0 && y % height == 0)
	{
		cout << "Точка находится на границе двух ромбов";
	}
	else if (sqrt(pow(centerX1 - x, 2) + pow(centerY1 - y, 2)) < sqrt(pow(centerX2 - x, 2) + pow(centerY2 - y, 2)))
	{
			(centerX1 / width) % 2 == 0 ? cout << "Точка попала в черный ромб" : cout << "Точка попала в желтый ромб";
	}
	else if (sqrt(pow(centerX1 - x, 2) + pow(centerY1 - y, 2)) > sqrt(pow(centerX2 - x, 2) + pow(centerY2 - y, 2)))
	{
			(centerX2 / width) % 2 == 0 ? cout << "Точка попала в черный ромб" : cout << "Точка попала в желтый ромб";
	}
	else if (sqrt(pow(centerX1 - x, 2) + pow(centerY1 - y, 2)) == sqrt(pow(centerX2 - x, 2) + pow(centerY2 - y, 2)))
	{
		cout << "Точка находится на границе двух ромбов";
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
