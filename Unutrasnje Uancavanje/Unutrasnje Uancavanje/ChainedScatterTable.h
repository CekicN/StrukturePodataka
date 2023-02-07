#pragma once
#include"HashTable.h"
#include"ChainedScatterObject.h"
class ChainedScatterTable : public HashTable
{
	ChainedScatterObject* niz;
	unsigned int lrmp;
public:
	ChainedScatterTable(int len);
	~ChainedScatterTable();

	void withdraw(const ChainedScatterObject& o);
	void withdraw(char* k);
	void insert(ChainedScatterObject el);
	void print();
	ChainedScatterObject find(char* key);
};

