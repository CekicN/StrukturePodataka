#pragma once
#include<iostream>
class HashObject
{
protected:
	char* key;
	char* ime;
	int brBodova;
	

public:
	HashObject();
	HashObject(const char* key, const char* ime, int br);	
	HashObject(const HashObject& o);
	~HashObject();

	HashObject& operator=(const HashObject& o);
	bool operator==(const HashObject& o);
	bool isEqual(char* key);
	void deleteValue();
	char* getKey() { return key; }
	char* getValue() { return ime; }
	void print();

	static int br;
};

