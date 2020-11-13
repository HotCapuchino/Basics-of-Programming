#pragma once
#include <string>
#include <ostream>

using namespace std;
class Number {
private:
	int base;
	string number;
	bool sign;
	int toDecimal(string num, int current_base);

	string toTargetNumberSystem(int num, int target_base);

public:

	friend Number changeBase(Number& num, int new_base);

	Number(string num);

	Number(string num, int base);

	~Number();

	int getBase();

	friend ostream& operator<<(ostream& out, Number& num);

	static Number power(Number& num, int pow);

	void operator =(Number& num);

	Number operator +(Number& num);

	Number operator -(Number& num);

	Number operator *(Number& num);

	Number operator /(Number& num);

	void operator +=(Number& num);

	void operator -=(Number& num);

	void operator *=(Number& num);

	void operator /=(Number& num);

	bool operator >(Number& num);

	bool operator <(Number& num);

	bool operator >=(Number& num);

	bool operator <=(Number& num);

	bool operator ==(Number& num);

	bool operator !=(Number& num);
};

Number changeBase(Number& num, int new_base);