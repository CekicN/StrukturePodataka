#pragma once
#include<iostream>
class HashObject
{
protected:
	int i, j;
	int value;

public:
	HashObject();
	HashObject(int i, int j);
	HashObject(int i, int j, int value);

	bool operator==(const HashObject& o);
	HashObject& operator=(const HashObject& o);
	int getValue() { return value; }
	void print();
};

