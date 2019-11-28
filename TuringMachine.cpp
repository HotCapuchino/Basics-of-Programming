// TuringMachine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;
    cout << "Enter your number: "; 
	setlocale(LC_ALL, "ru");
	int number;
	cin >> number;
	int one, two;
	one = number;
	string num = "";
	for (size_t i = 0; i < number; i++)
	{
		num = num + "1";
	}
	cout << num.c_str() << endl;
	int i = 1;
	for (i; i < number; i++)
	{
		if (i == number - 1) {
			num[i] = '0';
			cout << num.c_str() << endl;
			two = one + 2;
			for (one; one < two; one++)
			{
				num = num + "0";
				num[one] = '1';
			}
			cout << num.c_str() << endl;
			num[i] = '1';
			cout << num.c_str() << endl;
			one = two;
			num[0] = '0';
			cout << num.c_str() << endl;
			two = one + 2;
			for (one; one < two; one++)
			{
				num = num + "0";
				num[one] = '1';
			}
			cout << num.c_str() << endl;
			num[0] = '1';
			cout << num.c_str() << endl;
			break;
		}
		num[i] = '0';
		cout << num.c_str() << endl;
		two = one + 2;
		for(one; one < two; one++)
		{
			num = num + "0";
			num[one] = '1';
		}
		one = two;
		cout << num.c_str() << endl;
		num[i] = '1';
		cout << num.c_str() << endl;
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
