#pragma once
#include<iostream>
class HashObject
{
public:
	unsigned int key;
	unsigned int value;

	HashObject();
	HashObject(unsigned int key);
	HashObject(unsigned int key, unsigned int value);
	HashObject(const HashObject& o);

	HashObject& operator=(const HashObject& o);
	bool operator==(const HashObject& o);
	void print();
};

