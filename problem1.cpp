// problem1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool isPrime(string line) {
	int num = 0;
	num = stoi(line);
	for (size_t i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
void mainOperation(int arg) {
	const string input = "C:/problem2/examples/input";
	const string output = "C:/problem2/examples/myoutput";
	string line = "";
	string changed = "";
	ifstream in;
	ofstream out;
	bool primeChecked = false;
	in.open(input + to_string(arg) + ".dat");
	if (!in.is_open())
	{
		cout << "Error occured while opening the file!";
		return;
	}
	out.open(output + to_string(arg) + ".dat", ios::app);
	if (!out.is_open())
	{
		cout << "Error occured while creating the new file!";
		return;
	}
	else
	{
		while (getline(in, line))
		{
			changed = line;
			if (isPrime(line) != 1)
			{
				for (size_t i = 0; i < changed.length(); i++)
				{
					if (changed[i] == '0')
					{
						changed[i] = '9';
						if (isPrime(changed) && stoi(changed) < 200000 && stoi(changed) > 100000)
						{
							out << changed << " ";
							primeChecked = true;
						}
					}
					else
					{
						changed[i] -= 1;
						if (isPrime(changed) && stoi(changed) < 200000 && stoi(changed) > 100000)
						{
							out << changed << " ";
							primeChecked = true;
						}
					}
					changed = line;
				}
				if (!primeChecked)
				{
					out << changed + "*";
				}
				else {
					out << endl;
				}
				primeChecked = false;
			}
			else {
				out << line << endl;
			}
		}
	}
}

int main()
{
	mainOperation(1);
	mainOperation(2);
	mainOperation(3);
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
