#include "pch.h"
#include "Dict.h"


Dict::Dict()
{
	for (int j = 0; j < 10; j++) {
		letters[j] = (char)(j + 48);
	} 
	for (int j = 10; j < 36; j++) {
		letters[j] = (j + 7) + '0';
	}
	letters[36] = '\0';
}


Dict::~Dict()
{
}


int Dict::getKey(char elem)
{
	for (int i = 0; i < 36; i++) {
		if (letters[i] == elem) return i;
	}
}

char Dict::getValue(int index) {
	return letters[index];
}
