// Commercial.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;
    cout << "Enter the amount of credit!\n";
	double credit;
	cin >> credit;
	cout << "Enter an annual percent!\n";
	float annualPer;
	cin >> annualPer;
	cout << "Enter the predictable benefit!\n";
	double prediction;
	cin >> prediction;
	double sum = prediction;
	int i = 1;
	double velocityOfApproaching = credit - sum;
	bool codeRed = false;
	while (sum < credit)
	{
		sum = sum + prediction;
		credit = credit * (1 + (double) annualPer / 100);
		i++;
		if (velocityOfApproaching < credit - sum)
		{
			codeRed = true;
			break;
		}
		velocityOfApproaching = credit - sum;
	}
	if (!codeRed)
	{
		cout << "It requires " << i << " years to pay back";
	}
	else
	{
		cout << "The bouncers are already knocking at his door";
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
