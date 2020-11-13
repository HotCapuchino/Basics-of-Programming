#include "pch.h"
#include <iostream>
#include "Number.h"
#include <string>

using namespace std;
int main()
{ 
	Number my_num = Number("AA8", 16);
	/*cout << my_num << endl;*/
	/*string decimal = my_num.toDecimal("227", 8);
	cout << decimal << endl;*/
	/*my_num = changeBase(my_num, 10);*/
	Number just_num = Number("A", 16);
	Number test_num = Number("2738", 10);
	just_num = test_num;
	cout << just_num;
}