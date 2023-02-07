#pragma once
#include"HashTable.h"
#include"LList.h"
class ChainedHash : public HashTable
{
	LList* niz;
public:
	ChainedHash(int len);
	~ChainedHash();

	void insert(HashObject el);
	void withdraw(HashObject el);
	void withdraw(int key);

	HashObject find(int key);
	void print();
};

