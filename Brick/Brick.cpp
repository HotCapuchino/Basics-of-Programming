// Brick.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

double diagonal(int a, int b) {
	(double)a;
	(double)b;
	return sqrt(pow(a, 2) + pow(b, 2));
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using namespace std;
    cout << "Введите ширину кирпича\n";
	int width;
	cin >> width;
	cout << "Введите длину кирпича\n";
	int length;
	cin >> length;
	cout << "Введите высоту кирпича\n";
	int height;
	cin >> height;
	cout << "Введите ширину отверстия\n";
	double holeWidth;
	cin >> holeWidth;
	cout << "Введите длину отверстия\n";
	double holeLength;
	cin >> holeLength;
	double holeDiagonal = sqrt(pow(holeLength, 2) + pow(holeWidth, 2));
	if (holeDiagonal >= diagonal(width, length))
	{
		cout << "Кирпич входит";
	}
	else if (holeDiagonal >= diagonal(length, height))
	{
		cout << "Кирпич входит";
	} 
	else if (holeDiagonal >= diagonal(width, height))
	{
		cout << "Кирпич входит";
	}
	else
	{
		cout << "Кирпич не входит";
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
