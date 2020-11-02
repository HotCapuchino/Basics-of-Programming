#pragma once
#include <iostream>
#include "VectorException.h"

const int DEFAULT_CAPACITY = 10;
const long MAX_CAPACITY = INT_MAX;
class Vector {

private:
	int size;
	int capacity;
	int *ptr;
	void increaseCapacity(int newCapacity);

public:

	explicit Vector(int start_capacity); // constructor with defined capacity

	Vector(const Vector &vector); // copying constructor

	~Vector(); // destructor

	Vector& operator =(const Vector &vector); // initialization operator

	int& operator [](int index) const; // getting elem by its index

	bool operator ==(const Vector &vector); // comparising two vectors

	Vector& operator +(const Vector &vector); // adding

	void insert(int index, int elem); // insert elem to particular position

	void insert(int elem); // insert elem in the end of the vector

	void insert(int index, const Vector &vector); // inserting vector to particular position

	void insert(const Vector &vector); // inserting vector in the end of the vector

	void remove(int index); // removing elem
	
	void pop(); // removing last index

	void remove(int startIndex, int endIndex); // removing bunch of elems

	int getSize() const; // get vector's size

	friend std::ostream& operator <<(std::ostream& out, const Vector& vector); // print Vector
	
	int find(int elem); // find elem
};
