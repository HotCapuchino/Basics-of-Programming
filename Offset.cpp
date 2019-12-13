// Offset.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	using namespace std;
    cout << "Input size of array: ";
	int n;
	cin >> n;
	cout << "Input size of offset: ";
	int m;
	cin >> m;
	int box, box2;
	int *offsetArr = new int[n];
	int *secondArr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		secondArr[i] = 0;
		offsetArr[i] = rand() % 100 + 1;
		cout << offsetArr[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (i + m >= n) {
			box = offsetArr[(m + i) - n * ((m + i)/n)];
			secondArr[(m + i) - n * ((m + i) / n)] = offsetArr[i];
		}
		else {
			box = offsetArr[i + m];
			secondArr[i + m] = offsetArr[i];
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << secondArr[i] << " ";
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
