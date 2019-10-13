// NDChess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
int fact(int x, int factorial = 1) {
	factorial = factorial * x;
	if (x > 1)
	{
		fact(x - 1, factorial);
	}
	else if (x == 1) {
		return factorial;
	} 
	else if (x == 0) {
		return 1;
	}
}

int main()
{
	using namespace std;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите размерность измерения\n";
	int dimensions;
	cin >> dimensions;
	int *positions = new int[dimensions];
	for (size_t i = 0; i < dimensions; i++)
	{
		cout << "Введите " << i + 1 << " координату\n";
		cin >> positions[i];
		if (positions[i] > 8 || positions[i] < 1)
		{
			cout << "Ошибка ввода\n";
			return 0;
		}
	}
	int desks = fact(dimensions) / (fact(dimensions - 2) * 2);
	int generalStepsAmount = 8 * desks;
	int chessDesk[8][8] = { {6, 5, 4, 4, 4, 4, 5, 6}, {5, 4, 2, 2, 2, 2, 4, 5}, {4, 2, 0, 0, 0, 0, 2, 4}, {4, 2, 0, 0, 0, 0, 2, 4}, {4, 2, 0, 0, 0, 0, 2, 4}, {4, 2, 0, 0, 0, 0, 2, 4}, {5, 4, 2, 2, 2, 2, 4, 5}, {6, 5, 4, 4, 4, 4, 5, 6} };
	for (size_t i = 0; i < dimensions; i++)
	{
		for (size_t j = i + 1; j < dimensions; j++)
		{
			generalStepsAmount -= chessDesk[positions[i] - 1][positions[j] - 1];
		}
	}
	cout << "Коню доступно: " << generalStepsAmount << " ходов\n";
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
