#include "pch.h"
#include "QuickPow.h"


QuickPow::QuickPow()
{
}


QuickPow::~QuickPow()
{
}


int QuickPow::power(int num, int pow)
{
	if (pow == 0)
		return 1;
	if (pow % 2 != 0)
		return power(num, pow - 1) * num;
	else {
		return power(num * num, pow / 2);;
	}
}