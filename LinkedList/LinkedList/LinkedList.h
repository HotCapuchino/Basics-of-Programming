#pragma once
#include "LinkedListElem.h"
#include <string>

template<class T>
class LinkedList {
private:
	LinkedListElem<T>** elements = nullptr; // указатель на первый элемент массива всех элементов связного списка
	LinkedListElem<T>* start = nullptr; // указатель на первый элемент
	LinkedListElem<T>* end = nullptr; // указатель на последний элемент
	unsigned int size;
	unsigned int capacity;
	bool looped;
	////////////////////////////////////// done
	void increaseCapacity() {
		LinkedListElem<T>** new_elements = new LinkedListElem<T>*[capacity * 2];
		for (size_t i = 0; i < size; i++) {
			new_elements[i] = elements[i];
		}
		elements = new_elements;
		capacity *= 2;
	};
public:
	LinkedList() {
		looped = false;
		size = 0;
		capacity = 10;
		elements = new LinkedListElem<T>*[capacity];
	};

	LinkedList(bool looped, unsigned int capacity = 10) {
		this->looped = looped;
		size = 0;
		if (capacity > 0) this->capacity = capacity;
		elements = new LinkedListElem<T>*[capacity];
	};
	// to do

	~LinkedList() {
		while (start)
			removeFirst();
	};
	// done
	void addElement(T& elem_data) {
		if (size == capacity) this->increaseCapacity();
		if (size == 0) {
			start = new LinkedListElem<T>(elem_data);
			end = start;
			elements[size] = start;
			size++;
			return;
		}
		LinkedListElem<T>* new_elem = new LinkedListElem<T>(elem_data, end);
		this->getEnd()->setNext(new_elem);
		end = new_elem;
		if (looped) { 
			end->setNext(start); 
			start->setPrevious(end);
		}
		elements[size] = new_elem;
		size++;
	};

	// done
	void printElems() {
		LinkedListElem<T>* current_elem = start;
		int i = 0;
		while (true) {
			if (i >= size) break;
			if (current_elem->getNext() == nullptr) break;
			std::string next_data = current_elem->getNext() != nullptr ? " next: " + std::to_string(current_elem->getNext()->getData()) : "";
			std::cout << current_elem->getData() << next_data << std::endl;
			i++;
			current_elem = current_elem->getNext();
		}
	}

	/*void printAdresses() {
		for (size_t i = 0; i < size; i++) {
			std::cout << &elements[i] << std::endl;
		}
	}*/

	// done
	void insertAfterElement(T& elem_data, T& previous_elem_data) {
		if (this->isEmpty()) {
			std::cout << "List is empty!";
			return;
		}
		LinkedListElem<T>* previous_elem = this->getElement(previous_elem_data);
		if (previous_elem == nullptr) return;
		if (previous_elem == end) {
			this->addElement(elem_data);
			return;
		}
		if (size == capacity) this->increaseCapacity();
		LinkedListElem<T>* new_elem = new LinkedListElem<T>(elem_data, previous_elem, previous_elem->getNext());
		previous_elem->getNext()->setPrevious(new_elem);
		previous_elem->setNext(new_elem);
		elements[size] = new_elem;
		size++;
	};

	void insertBeforeElement(T& elem_data, T& next_elem_data) {
		if (this->isEmpty()) {
			std::cout << "List is empty!";
			return;
		}
		LinkedListElem<T>* next_elem = this->getElement(next_elem_data);
		if (next_elem == nullptr) return;
		LinkedListElem<T>* new_elem = new LinkedListElem<T>(elem_data);
		if (size == capacity) this->increaseCapacity();
		if (next_elem == start) {
			new_elem->setNext(start);
			this->getStart()->setPrevious(new_elem);
			start = new_elem;
			if (looped) {
				start->setPrevious(end);
				end->setNext(start);
			}
			elements[size] = new_elem;
			size++;
		} else {
			next_elem->getPrevious()->setNext(new_elem);
			new_elem->setPrevious(next_elem->getPrevious());
			new_elem->setNext(next_elem);
			next_elem->setPrevious(new_elem);
			elements[size] = new_elem;
			size++;
		}
	};

	void removeElement(T& elem_data) {
		LinkedListElem<T>* target_elem = this->getElement(elem_data);
		if (target_elem != nullptr) {
			LinkedListElem<T>* previous_elem = target_elem->getPrevious();
			LinkedListElem<T>* next_elem = target_elem->getNext();
			previous_elem->setNext(next_elem);
			next_elem->setPrevious(previous_elem);
			int removingElem_index = this->getElementPosition(elem_data);
			delete target_elem;
			elements[removingElem_index] = nullptr;
			size--;
		}
	};

	void removeLast() {
		if (looped) {
			start->setPrevious(end->getPrevious());
			end->getPrevious()->setNext(start);
		}
		T end_data = end->getData();
		int end_index = this->getElementPosition(end_data);
		end = end->getPrevious();
		delete this->getElement(end_data);
		elements[end_index] = nullptr;
		size--;
	};

	void removeFirst() {
		LinkedListElem<T>* next_elem = start->getNext();
		T start_data = start->getData();
		int start_index = this->getElementPosition(start_data);
		if (looped) {
			next_elem->setPrevious(end);
		}
		else next_elem->setPrevious(nullptr);
		end->setNext(next_elem);
		delete start;
		elements[start_index] = nullptr;
		start = next_elem;
		size--;
	};

	//////////////////////////////////////////////// done
	LinkedListElem<T>* getElement(T& elem_data) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == nullptr) continue;
			if (elements[i]->getData() == elem_data) {
				return elements[i];
			}
		}
		return nullptr;
	};

	int getElementPosition(T& elem_data) {
		for (int i = 0; i < size; i++) {
			if (elements[i] == nullptr) continue;
			if (elements[i]->getData() == elem_data) {
				return i;
			}
		}
		return -1;
	}

	int getSize() {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (elements[i] != nullptr) {
				counter++;
			}
		}
		return counter;
	};

	bool isEmpty() {
		return size > 0 ? false : true;
	};

	LinkedListElem<T>* getStart() {
		return start;
	};

	LinkedListElem<T>* getEnd() {
		return end;
	}

	friend class LinkedListElem<T>;
};

