// sixth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;
    cout << "Enter amount of students: ";
	int n;
	cin >> n;
	int noPresence = 0, bad = 0, satisfied = 0, well = 0, excellent = 0;
	string marks = "";
	int **mark_table = new int*[3];
	for (size_t i = 0; i < 3; i++)
	{
		mark_table[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			mark_table[i][j] = rand() % 5 + 1;
			cout << mark_table[i][j] << " ";
			switch (mark_table[i][j])
			{
				case 1: noPresence++;
					break;
				case 2: bad++;
					break;
				case 3: satisfied++;
					break;
				case 4: well++;
					break;
				case 5: excellent++;
					break;
			}
		}
		marks += string("Exam ") + string(to_string(i + 1)) + string(" marks: \nNo Presence: ") + string(to_string(noPresence)) + string(" Bad: ") + string(to_string(bad)) + 
		string(" Satisified: ") + string(to_string(satisfied)) + string(" Well: ") + string(to_string(well)) + string(" Excellent: ") + string(to_string(excellent)) + string("\n");
		noPresence = 0, bad = 0, satisfied = 0, well = 0, excellent = 0;
		cout << endl;
	}
	cout << marks;
	for (size_t i = 0; i < 3; i++)
	{
		delete mark_table[i];
	}
	delete[] mark_table;
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
