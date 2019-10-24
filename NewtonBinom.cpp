// NewtonBinom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>

int fact(int x) {
	int box = 1;
	for (int i = 1; i <= x; i++)
	{
		box = box * i;
	}
	return box;
}
int combination(int i, int m) {
	int box = 1;
	if (i >= 1)
	{
		box = combination(i - 1, m) * (double)(m - i + 1) / i;
	}
	else
	{
		return box;
	}
}

int main()
{
	using namespace std;
    cout << "Enter the value of m (degree)!\n"; 
	int m;
	cin >> m;
	cout << "Enter x!\n";
	int x;
	cin >> x;
	double result = 1.0;
	double sum = 0.0;
	clock_t firstTime, secondTime;
	for (size_t i = 0; i < m; i++)
	{
		result = result * (1 + x);
	}
	cout << "Regular way: " << result << endl;
	clock_t start = clock();
	for (size_t i = 0; i <= m; i++)
	{
		sum = sum + fact(m) / (fact(i) * fact(m - i)) * pow(x, i);
	}
	clock_t end = clock();
	firstTime = end - start;
	cout << "Using Newton formula with a classic formula for combination: " << sum << endl;
	sum = 0.0;
	start = clock();
	for (size_t i = 0; i <= m; i++)
	{
		sum = sum + combination(i, m) * pow(x, i);
	}
	end = clock();
	secondTime = end - start;
	cout << "Using Newton formula with a recurrent formula for combination: " << sum << endl;
	printf("The First time: %f seconds", firstTime);
	cout << endl;
	printf("The Second time: %f seconds", secondTime);
	cout << endl;
	if (firstTime > secondTime)
	{
		cout << "Recurrent formula for combination is more efficient";
	}
	else {
		cout << "Classic formula for combination is more efficient";
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
