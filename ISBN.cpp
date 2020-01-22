// ISBN.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num) {
	for (size_t i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

string ISBNCheck(string line) {
	int num = 0;
	string copiedLine = line;
	if (line[line.length() - 1] != 'X')
	{
		num = stoi(line);
	}
	else
	{
		line[line.length() - 1] = '\0';
		num = stoi(line);
	}
	int sum = 0;
	if (!isPrime(num))
	{
		return "---";
	}
	for (int i = copiedLine.size(); i >= 0; i--)
	{
		if (copiedLine[i] == 'X')
		{
			sum += 10 * (i + 1);
		}
		else {
			sum += ((int)copiedLine[i] - '0') * (i + 1);
		}
	}
	if (sum % 11 == 0)
	{
		return copiedLine;
	}
	else {
		return "---";
	}
}

int main()
{
	string buffer = "";
	string previousNum = "";
	cout << "Searching for all ISBN: " << endl;
	for (int i = 1000000000; i < 10000000000; i++)
	{ 
		buffer = ISBNCheck(to_string(i));
		if (buffer != "---")
		{
			cout << buffer << endl;
		}
		buffer = to_string(i);
		buffer[buffer.length() - 1] = 'X';
		buffer = ISBNCheck(buffer);
		if (buffer != "---" && buffer != previousNum)
		{
			cout << buffer << endl;
			previousNum = buffer;
		}
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
