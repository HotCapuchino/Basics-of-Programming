#pragma once
class Dict {
private: 
	char letters[37];
public:
	Dict();

	~Dict();

	int getKey(char elem);

	char getValue(int index);
};

