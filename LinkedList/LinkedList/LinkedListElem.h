#pragma once
#include "LinkedListException.h"
#include <iostream>

template<class T>
class LinkedListElem {
private:
	T data;
	LinkedListElem<T>* previous_elem;
	LinkedListElem<T>* next_elem;
public:
	LinkedListElem() {
		data = T();
		previous_elem = nullptr;
		next_elem = nullptr;
	};

	LinkedListElem(T& data, LinkedListElem<T>* previous_elem = nullptr, LinkedListElem<T>* next_elem = nullptr) {
		this->data = data;
		this->previous_elem = previous_elem;
		this->next_elem = next_elem;
	};

	void setNext(LinkedListElem<T>* next_elem) {
		this->next_elem = next_elem;
	};

	void setPrevious(LinkedListElem<T>* previous_elem) {
		this->previous_elem = previous_elem;
	};

	LinkedListElem<T>* getNext() {
		if (next_elem == nullptr) {
			std::cout << "Element has no subsequent sibling!";
		}
		return next_elem;
	};

	LinkedListElem<T>* getPrevious() {
		if (previous_elem == nullptr) {
			std::cout << "Element has no previous sibling!";
		}
		return previous_elem;
	};

	T getData() {
		return data;
	};

	~LinkedListElem() {};

};
