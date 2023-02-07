#pragma once
#include<iostream>
using namespace std;
class HashObject
{
protected:
	char* key;
	char* record;

public:
	HashObject();
	HashObject(char* key);
	HashObject(char* key, char* record);
	HashObject(const HashObject& o);
	~HashObject();
	HashObject& operator=(const HashObject& o);
	bool operator==(const HashObject& o);

	void deleteRecord();
	char* GetKey() { return key; }
	char* GetRecord() { return record; }
	bool isEqualKey(char* k) { return strcmp(key, k) == 0; }
	void print();
};

