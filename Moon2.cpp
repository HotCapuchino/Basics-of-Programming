#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

string timeConvert(double &time, int &HMSPrevious) {
	double hoursP, minutesP, secondsP, buf;
	secondsP = HMSPrevious % 100;
	minutesP = HMSPrevious % 10000 / 100;
	hoursP = HMSPrevious / 10000;
	time + secondsP >= 60.0 ? buf = secondsP, secondsP = (int)(time + (secondsP)) % 60, minutesP += (time + (buf)) / 60 : secondsP += time + (secondsP);								// функция преобразования времени
	minutesP >= 60.0 ? buf = minutesP, minutesP = (int)minutesP % 60, hoursP += buf / 60 : minutesP = minutesP;
	hoursP >= 24 ? hoursP = (int)hoursP % 24 : hoursP = hoursP;
	cout.precision(2);
	string result = to_string(int(hoursP)) + ":" + to_string(int(minutesP)) + ":" + to_string(int(secondsP));
	return result;
}

int main()
{
	char line1[75];
	string line2;
	ifstream in;
	int searchDate = 0, year = 0, month = 0, day = 0;
	int YMD, HMS, HMSPrevious, HMSmax, YMDmax;
	double T, R, El, ElPrevious, Az, FI, LG;
	double maxEl = 0, secondmaxEl = 0;
	double seconds;
	bool itWasFound = false;
	int appliance;
	bool invalidData = true;
	while (invalidData)
	{
		cout << "Enter date in format: DD.MM.YYYY" << endl;
		scanf_s("%d.%d.%d", &day, &month, &year);
		if (day > 31 || month > 12 || day < 1 || month < 1)
		{
			cout << "Invalid data!" << endl;
		}
		else
		{
			invalidData = false;
		}
		cin.clear();
		while (cin.get() != '\n');
	}
	searchDate = year * 10000 + month * 100 + day;									// создание даты, которая будм искать
	in.open("Data/MoonTask/moon" + to_string(year) + ".dat");
	if (!in.is_open()) {
		cout << "Error occured while trying open the file" << endl;
		return -1;
	}
	double s = clock();
	bool moonriseFound = false, moonsetFound = false, moonpeakFound = false;
	string maxRes = "";

	while (getline(in, line2))
	{
		in.getline(line1, 75);
		sscanf_s(line1, "%d %d %lf %lf %lf", &YMD, &HMS, &T, &R, &El);
		if (YMD == searchDate)
		{
			itWasFound = true;
			while (YMD == searchDate || !moonriseFound || !moonsetFound || !moonpeakFound) {			// ищем до тех пор, пока не будут найдены восход, зенит и закат	
				in.getline(line1, 75);
				ElPrevious = El;
				HMSPrevious = HMS;
				if (El - maxEl > 0.0000005 && El > 0)
				{
					maxEl = El;
					HMSmax = HMS;
					YMDmax = YMD;
					moonpeakFound = true;
				}
				sscanf_s(line1, "%d %d %lf %lf %lf", &YMD, &HMS, &T, &R, &El);
				if (ElPrevious * El < 0 && El > 0 && !moonriseFound)
				{
					seconds = (0 - ElPrevious) / ((El - ElPrevious) / abs((((HMS / 10000 - HMSPrevious / 10000) * 60) + (HMS % 10000 / 100 - HMSPrevious % 10000 / 100)) * 60 + (HMS % 100 - HMSPrevious % 100)));			// расчет времени, за которое угол луны изменился до 0 градусов
					cout << "Time of moonrise: ";
					cout << timeConvert(seconds, HMSPrevious);																																								// формирование точного времени 
					cout << " on the " << YMD % 100 << " of " << YMD % 10000 / 100 << " month of " << YMD / 10000;
					cout << endl;
					moonriseFound = true;
				} else if (ElPrevious * El == 0 && ElPrevious < 0 && !moonriseFound)
				{
					cout << "Time of moonrise: " << HMS / 10000 << ":" << HMS % 10000 / 100 << ":" << HMS % 100 << endl;
				}
				else if (ElPrevious * El < 0 && El < 0 && !moonsetFound)
				{
					seconds = ElPrevious / ((ElPrevious - El) / abs((((HMS / 10000 - HMSPrevious / 10000) * 60) + (HMS % 10000 / 100 - HMSPrevious % 10000 / 100)) * 60 + (HMS % 100 - HMSPrevious % 100)));
					cout << "Time of moonset: ";
					cout << timeConvert(seconds, HMSPrevious);
					cout << " on the " << YMD % 100 << " of " << YMD % 10000 / 100 << " month of " << YMD / 10000;
					cout << endl;
					moonsetFound = true;
				} else if (ElPrevious * El == 0 && ElPrevious > 0 && !moonsetFound)
				{
					cout << "Time of moonset: " << HMS / 10000 << ":" << HMS % 10000 / 100 << ":" << HMS % 100 << endl;
				}
				if (El == ElPrevious && El == maxEl) {
					secondmaxEl = El;
					HMSmax = HMSPrevious;
					YMDmax = YMD;
					moonpeakFound = true;
					in.getline(line1, 75);
					sscanf_s(line1, "%d %d %lf %lf %lf", &YMD, &HMS, &T, &R, &El);
					while (El == ElPrevious)
					{
						in.getline(line1, 75);
						ElPrevious = El;
						HMSPrevious = HMS;
						sscanf_s(line1, "%d %d %lf %lf %lf", &YMD, &HMS, &T, &R, &El);
					}
					seconds = abs((((HMS / 10000 - HMSmax / 10000) * 60) + (HMS % 10000 / 100 - HMSmax % 10000 / 100)) * 60 + (HMS % 100 - HMSmax % 100)) / 2;																// расчет времени между 2 крайними точками, когда луна находилась в зените
					maxRes = timeConvert(seconds, HMSmax);																																									// формирование точного времени
				}
				if (in.eof())
				{
					break;
				}
			}
		}
	}
	if (!itWasFound)
	{
		cout << "There is no such date in the file!" << endl;																					// сработает, если даты не будет в файле
	}
	if (secondmaxEl >= maxEl) {
		cout << "Time when moon has its peak: " << maxRes;
		cout << " on the " << YMDmax % 100 << " of " << YMDmax % 10000 / 100 << " month of " << YMDmax / 10000;									// сработает, если было найдено несколько точек, где луна была в зените
	}
	else
	{
		cout << "Time when moon has its peak: " << HMSmax / 10000 << ":" << HMSmax % 10000 / 100 << ":" << HMSmax % 100;						// сработает, если была найдена всего одна точка нахождения луны в зените
		cout << " on the " << YMDmax % 100 << " of " << YMDmax % 10000 / 100 << " month of " << YMDmax / 10000;
	}
	/*printf("Time spent: %lf\n", (clock() - s) / CLOCKS_PER_SEC);*/
}