#include "pch.h"
#include "Vector.h"

Vector::Vector(int start_capacity) { // constructor with defined capacity
	if (start_capacity <= 0) {
		capacity = DEFAULT_CAPACITY;
	}
	else {
		capacity = start_capacity;
	}
	ptr = new int[capacity];
	size = 0;
}

Vector::~Vector() { // destructor
	delete[] ptr;
};

Vector::Vector(const Vector &vector) { // copying constructor
	ptr = new int[vector.capacity];
	size = vector.size;
	capacity = vector.capacity;
	for (int i = 0; i < vector.size; i++)
	{
		ptr[i] = vector.ptr[i];
	}
};

Vector& Vector::operator =(const Vector &vector) { // initialization operator
	if (this == &vector) {
		return *this;
	}
	if (capacity != vector.capacity) {
		delete[] ptr;
		ptr = new int[vector.capacity];
		capacity = vector.capacity;
	}
	size = vector.size;
	for (int i = 0; i < vector.size; i++)
	{
		ptr[i] = vector.ptr[i];
	}
	return *this;
}

int& Vector::operator [](int index) const { // getting elem by its index
	if (index < 0 || index >= size) {
		throw VectorException();
	}
	else {
		return ptr[index];
	}
};

bool Vector::operator ==(const Vector &vector) {
	if (size != vector.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != vector.ptr[i]) {
				return false;
			}
		}
		return true;
	}
};

Vector& Vector::operator +(const Vector &vector) {
	Vector new_vector(size + vector.size);
	int currentIndex = size;
	for (int i = 0; i < size; i++)
	{
		new_vector.insert(ptr[i]);
	}
	for (int i = 0; i < vector.size; i++)
	{
		new_vector.insert(vector.ptr[i]);
	}
	return new_vector;
}
 
void Vector::increaseCapacity(int newCapasity) { // increasing capacity
	if (newCapasity > MAX_CAPACITY || (long)(capacity * 2) > MAX_CAPACITY) {
		throw VectorException();
	}
	capacity = newCapasity < capacity * 2 ? capacity * 2 : newCapasity;
	int *newPtr = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		newPtr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newPtr;
};

void Vector::insert(int index, int elem) { //  insert elem to particular position
	if (index < 0 || index > size) {
		throw VectorException();
	} 
	if (index == size && size == capacity) {
		increaseCapacity(size * 2);
	}
	for (int i = size - 1; i >= index; i--)
	{
		ptr[i + 1] = ptr[i];
	}
	size++;
	ptr[index] = elem;
};

void Vector::insert(int elem) { // insert elem in the end of the vector
	if (size == capacity) {
		increaseCapacity(size * 2);
	}
	ptr[size] = elem;
	size++;
};

void Vector::insert(int index, const Vector &vector) { // inserting vector to particular position
	if (index < 0 || index > size) {
		throw VectorException();
	}
	if (index == size || size + vector.size >= capacity) {
		increaseCapacity(size + vector.size);
	}
	for (int i = size - 1; i >= index; i--)
	{
		ptr[i + vector.size] = ptr[i];
	}
	int currentIndex = index;
	for (int i = 0; i < vector.size; i++)
	{
		ptr[currentIndex] = vector.ptr[i];
		currentIndex++;
	}
	size += vector.size;
};

void Vector::insert(const Vector &vector) { // inserting vector in the end of the vector
	if (size + vector.size >= capacity) {
		increaseCapacity(size + vector.size);
	}
	int currentIndex = size;
	for (int i = 0; i < vector.size; i++)
	{
		ptr[currentIndex] = vector.ptr[i];
		currentIndex++;
	}
	size += vector.size;
};

void Vector::remove(int index) { // removing elem
	if (index < 0 || index >= size) {
		throw VectorException();
	}
	for (int i = index; i < size; i++)
	{
		ptr[i] = ptr[i + 1];
	}
	ptr[size - 1] = NULL;
	size--;
};

void Vector::pop() { // removing last elem
	ptr[size - 1] = NULL;
	size--;
}

void Vector::remove(int startIndex, int endIndex) { // removing bunch of elems
	if (startIndex < 0 || startIndex > size - 1 || endIndex < 0 || endIndex > size - 1) {
		throw VectorException();
	}
	if (endIndex < startIndex) {
		int buf = startIndex;
		startIndex = endIndex;
		endIndex = buf;
	}
	int difference = 0;
	if (startIndex == endIndex) {
		difference = 1;
	}
	else {
		difference = endIndex - startIndex + 1;
	}
	for (int i = startIndex; i < endIndex; i++)
	{
		if (i + difference >= size) {
			break;
		}
		ptr[i] = ptr[i + difference];
	}
	size -= difference;
}

int Vector::getSize() const { // getting size
	return size;
};

std::ostream& operator <<(std::ostream& out, const Vector& vector) { // printing Vector
	out << "Total size: " << vector.size << std::endl;
	out << "Total capacity: " << vector.capacity << std::endl;
	for (size_t i = 0; i < vector.size; i++)
	{
		out << vector.ptr[i] << " ";
	}
	return out;
};