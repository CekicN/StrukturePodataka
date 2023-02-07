#pragma once
#include"HashTable.h"
#include"LList.h"
class ChainedHashTable:public HashTable
{
	LList* niz;
public:
	ChainedHashTable(unsigned int len);
	~ChainedHashTable();
	void insert(HashObject obj);
	void withdraw(HashObject obj);
	void withdraw(char* key);
	HashObject find(char* key);
	void print();
};

