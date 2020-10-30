#include "pch.h"
#include <iostream>

using namespace std;
typedef unsigned long long mll;
const mll base = INT_MAX;

class BigNumbers {
private:
	mll bigNumber;
public:
	void add(mll num1, mll num2);
	void divide(mll num, mll divisor);
};

class Rationals {

private:

	int num;
	int denom;

	void simplify() {
		if (denom < 0) {
			num = -num;
			denom = -denom;
		}
		for (int i = 2; i <= abs(denom) && i <= abs(num); i++) {
			if (num % i == 0 && denom % i == 0)
			{
				num /= i;
				denom /= i;
				i--;
			}
		}
	}

public:

	Rationals() {
		num = 0;
		denom = 1;
	}

	Rationals(int num) {
		this->num = num;
		denom = 1;
		simplify();
	}

	Rationals(int num, int denom) {
		this->num = num;
		if (denom == 0) {
			this->denom = 1;
		}
		else
		{
			this->denom = denom;
		}
		simplify();
	}

	 friend istream& operator >>(istream& in, Rationals& r) {
		in >> r.num >> r.denom;
		return in;
	}

	 friend ostream& operator <<(ostream& out, const Rationals& r)
	 {
		 out << r.num << "/" << r.denom;
		 return out;
	 }

	Rationals operator +=(Rationals& r) { 
		if (r.denom != denom) {
			num = num * r.denom + r.num*denom;
			denom *= r.denom;
		}
		else {
			num += r.num;
		}
		simplify();
		return *this;
	}

	Rationals operator +(Rationals& r) { // сложение
		Rationals res(*this);
		return res += r;
	}

	Rationals operator -=(Rationals& r) { 
		if (r.denom != denom) {
			num = num * r.denom - r.num*denom;
			denom *= r.denom;
		}
		else {
			num -= r.num;
		}
		simplify();
		return *this;
	}

	Rationals operator -(Rationals& r) { // вычитание
		int new_num;
		int new_denom;
		if (denom != r.denom) {
			new_num = num * r.denom - r.num*denom;
			new_denom = denom * r.denom;
		}
		else {
			new_num = num - r.num;
		}
		Rationals new_rational = Rationals(new_num, new_denom);
		return new_rational;
	}

	Rationals operator *=(Rationals& r) { 
		num *= r.num;
		denom *= r.denom;
		simplify();
		return *this;
	}

	Rationals operator *(Rationals& r) { // умножение
		int new_num = num * r.num;
		int new_denom = denom * r.denom;
		Rationals new_rational = Rationals(new_num, new_denom);
		return new_rational;
	}

	Rationals operator /=(Rationals& r) { 
		num *= r.denom;
		denom *= r.num;
		simplify();
		return *this;
	}

	Rationals operator /(Rationals& r) { // деление
		int new_num = num * r.denom;
		int new_denom = denom * r.num;
		Rationals new_rational = Rationals(new_num, new_denom);
		return new_rational;
	}
	
	Rationals operator ++() {
		num += denom;
		return *this;
	}

	Rationals operator ++(int) {
		Rationals r(*this);
		num += denom;
		return r;
	}

	bool operator ==(const Rationals& r) const
	{
		return (num == r.num) && (denom == r.denom);
	}

	bool operator !=(const Rationals& r) const
	{
		return !(*this == r);
	}

	bool operator <(const Rationals& r) const
	{
		return (num*r.denom < denom*r.num);
	}

	bool operator >(const Rationals& r) const
	{
		return !(num*r.denom < denom*r.num);
	}

	bool operator <=(const Rationals& r) const
	{
		return (num*r.denom <= denom*r.num);
	}

	bool operator >=(const Rationals& r) const
	{
		return !(num*r.denom <= denom*r.num);
	}

	operator int() const
	{
		return num / denom;
	}

	operator double() const
	{
		return ((double)num / denom);
	}

	static Rationals simpleSqrt(Rationals& r, int iterations) { // извлечение квадратного корня
		Rationals initial = Rationals(1);
		Rationals divider = Rationals(1, 2);
		Rationals buf;
		int buf_num = 0, buf_denom = 0;
		int overflow_num = 0, overflow_denom = 0;
		for (size_t i = 0; i < iterations; i++)
		{
			// это может быть полезно
			 

			/*buf_num *= initial.denom;
			buf_denom *= initial.num;
			if (buf_num < 0 && buf_denom < 0) {
				overflow_num = buf_num - INT_MIN;
				overflow_denom = buf_denom - INT_MIN;
				cout << "Overflow happened!\n";
				cout << "Current numerator: " << buf_num << endl;
				cout << "Current denominator: " << buf_denom << endl;
			}
			else if (buf_num < 0) {
				overflow_num = buf_num - INT_MIN;
				cout << "Overflow happened!\n";
				cout << "Current numerator: " << buf_num << endl;
				cout << "Current denominator: " << buf_denom << endl;
			}
			else if (buf_denom < 0) {
				overflow_denom = buf_denom - INT_MIN;
				cout << "Overflow happened!\n";
				cout << "Current numerator: " << buf_num << endl;
				cout << "Current denominator: " << buf_denom << endl;
			}*/


			// в перспективе
			buf = r / initial;
			buf += initial;
			initial = divider * buf;
		}
		return initial;
	}
};



int main()
{
	Rationals r1 = Rationals(3, 12);
	Rationals r2 = Rationals(5, 11);
	Rationals r3 = r1 + r2;
	cout << Rationals::simpleSqrt(r2, 3);
}