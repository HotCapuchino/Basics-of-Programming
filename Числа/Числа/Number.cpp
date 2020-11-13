#include "pch.h"
#include "Number.h"
#include "Dict.h"
#include <string>
#include "QuickPow.h"
#include <algorithm>

using namespace std;

Number::Number(string num) {
	int target_base = 2;
	Dict my_dict = Dict();
	for (int i = 0; i < num.length(); i++) {
		if (my_dict.getKey(num[i]) > target_base) {
			target_base = my_dict.getKey(num[i]) + 1;
		}
	}
	this->base = target_base;
	number = num;
}

Number::Number(string num, int base) {
	int target_base = 2;
	Dict my_dict = Dict();
	for (int i = 0; i < num.length(); i++) {
		if (my_dict.getKey(num[i]) > target_base) {
			target_base = my_dict.getKey(num[i]) + 1;
		}
	}
	target_base > base ? (this->base = target_base) : (this->base = base);
	number = num;
}

Number::~Number() {}

int Number::toDecimal(string num, int current_base) {
	int decimal_num = 0;
	Dict new_dict = Dict();
	for (int i = 0; i < num.length(); i++) {
		decimal_num += new_dict.getKey(num[i]) * QuickPow::power(current_base, num.length() - 1 - i);
	}
	return decimal_num;
}

string Number::toTargetNumberSystem(int num, int target_base)
{
	Dict my_dict = Dict();
	if (target_base < 2) target_base = 2;
	string reversed_result = "";
	string result = "";
	int remained = 0;
	while (true) {
		remained = num % target_base;
		reversed_result += my_dict.getValue(remained);
		num /= target_base;
		if (num < target_base) {
			if (num != 0) {
				reversed_result += my_dict.getValue(num);
			}
			break;
		}  
	}
	for (int i = reversed_result.length() - 1; i >= 0; i--) {
		result += reversed_result[i];
	}
	return result;
}

int Number::getBase()
{
	return base;
}

ostream & operator<<(ostream& out, Number & num)
{
	out << num.number;
	return out;
}

Number changeBase(Number& num, int new_base) {
	return Number(num.toTargetNumberSystem(num.toDecimal(num.number, num.base), new_base));
}


Number Number::power(Number & num, int pow) {
	return Number(num.toTargetNumberSystem(QuickPow::power(num.toDecimal(num.number, num.base), pow), num.base));
}

void Number::operator =(Number & num) {
	if (num.base != this->base) {
		this->number = num.toTargetNumberSystem(num.toDecimal(num.number, num.base), this->base);
	}
	else {
		this->number = num.number;
	}
}


Number Number::operator +(Number & num)
{
	int target_base = this->base;
	int sum = num.toDecimal(num.number, num.base) + this->toDecimal(this->number, this->base);
	Number new_num = Number(to_string(sum), 10);
	return changeBase(new_num, target_base);
}

Number Number::operator -(Number & num)
{
	int target_base = this->base;
	int substract = this->toDecimal(this->number, this->base) - num.toDecimal(num.number, num.base);
	Number new_num = Number(to_string(substract), 10);
	return changeBase(new_num, target_base);
}

Number Number::operator *(Number & num)
{
	int target_base = this->base;
	int multiply = this->toDecimal(this->number, this->base) * num.toDecimal(num.number, num.base);
	Number new_num = Number(to_string(multiply), 10);
	return changeBase(new_num, target_base);
}

Number Number::operator /(Number & num)
{
	int target_base = this->base;
	int divided = this->toDecimal(this->number, this->base) / num.toDecimal(num.number, num.base);
	Number new_num = Number(to_string(divided), 10);
	return changeBase(new_num, target_base);
}

void Number::operator +=(Number & num)
{
	int target_base = this->base;
	int added = num.toDecimal(num.number, num.base) + this->toDecimal(this->number, this->base);
	this->number = this->toTargetNumberSystem(added, this->base);
}

void Number::operator -=(Number & num)
{
	int target_base = this->base;
	int added = this->toDecimal(this->number, this->base) - num.toDecimal(num.number, num.base);
	this->number = this->toTargetNumberSystem(added, this->base);
}

void Number::operator *=(Number & num)
{
	int target_base = this->base;
	int added = this->toDecimal(this->number, this->base) * num.toDecimal(num.number, num.base);
	this->number = this->toTargetNumberSystem(added, this->base);
}

void Number::operator /=(Number & num)
{
	int target_base = this->base;
	int added = this->toDecimal(this->number, this->base) / num.toDecimal(num.number, num.base);
	this->number = this->toTargetNumberSystem(added, this->base);
}

bool Number::operator <(Number & num)
{
	return this->toDecimal(this->number, this->base) < num.toDecimal(num.number, num.base); 
} 

bool Number::operator >(Number & num)
{
	return this->toDecimal(this->number, this->base) > num.toDecimal(num.number, num.base);
}

bool Number::operator <=(Number & num)
{
	return this->toDecimal(this->number, this->base) <= num.toDecimal(num.number, num.base);
}

bool Number::operator >=(Number & num)
{
	return this->toDecimal(this->number, this->base) >= num.toDecimal(num.number, num.base);
}

bool Number::operator==(Number & num)
{
	return this->toDecimal(this->number, this->base) == num.toDecimal(num.number, num.base);
}

bool Number::operator!=(Number & num)
{
	return this->toDecimal(this->number, this->base) != num.toDecimal(num.number, num.base);
}