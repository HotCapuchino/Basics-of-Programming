#include "pch.h"
#include <iostream>
#include "Vector.h"
#include <climits>

using namespace std;
int main() {
	Vector my_vector(10);
	for (size_t i = 0; i < 6; i++)
	{
		my_vector.insert(i, i);
	}
	cout << my_vector << endl;
	my_vector.remove(2, 4);
	cout << my_vector << endl;
	my_vector.insert(6);
	cout << my_vector << endl;
	Vector my_vector2(5);
	my_vector2 = my_vector;
	cout << boolalpha <<(my_vector == my_vector2) << endl;
	my_vector.insert(2, my_vector2);
	cout << my_vector << endl;
	my_vector.pop();
	cout << my_vector << endl;
	cout << boolalpha << (my_vector == my_vector2) << endl;
	// doesn't work
	/*Vector v1(2);
	v1.insert(1);
	v1.insert(2);
	Vector v2(1);
	v2.insert(3);
	cout << v1 + v2;*/
}