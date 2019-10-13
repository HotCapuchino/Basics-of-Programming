// Triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>

int main()
{
	using namespace std;
    cout << "Enter x1, y1\n"; 
	int x1, y1;
	cin >> x1 >> y1;
	cout << "Enter x2, y2\n";
	int x2, y2;
	cin >> x2 >> y2;
	cout << "Enter x3, y3\n";
	int x3, y3;
	cin >> x3 >> y3;
	cout << "Enter x, y cordinates of dot\n";
	int x, y;
	cin >> x >> y;
	double firstSide, secondSide, thirdSide;
	firstSide = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	secondSide = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	thirdSide = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	double firstVector, secondVector, thirdVector;
	firstVector = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
	secondVector = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
	thirdVector = sqrt(pow(x - x3, 2) + pow(y - y3, 2));
	double generalSquare, firstSquare, secondSquare, thirdSquare, halfPerimetr;
	halfPerimetr = (firstSide + secondSide + thirdSide) / 2;
	generalSquare = sqrt(halfPerimetr*(halfPerimetr - firstSide) * (halfPerimetr - secondSide) * (halfPerimetr - thirdSide));
	halfPerimetr = (firstVector + secondVector + firstSide) / 2;
	firstSquare = sqrt(halfPerimetr*(halfPerimetr - firstVector) * (halfPerimetr - secondVector) * (halfPerimetr - firstSide));
	halfPerimetr = (thirdVector + secondVector + secondSide) / 2;
	secondSquare = sqrt(halfPerimetr*(halfPerimetr - thirdVector) * (halfPerimetr - secondVector) * (halfPerimetr - secondSide));
	halfPerimetr = (firstVector + thirdVector + thirdSide) / 2;
	thirdSquare = sqrt(halfPerimetr*(halfPerimetr - firstVector) * (halfPerimetr - thirdVector) * (halfPerimetr - thirdSide));
	if (abs(generalSquare - (firstSquare + secondSquare + thirdSquare)) < 0.0000000001) 
	{
		cout << generalSquare << " " << firstSquare + secondSquare + thirdSquare;
		cout << "Dot belongs to the triangle";
	}
	else
	{
		cout << generalSquare << " " << firstSquare + secondSquare + thirdSquare;
		cout << "Dot doesn't belong to the triangle\n";
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
