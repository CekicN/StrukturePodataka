#pragma once
#include"HashTable.h"
#include"ChainedScatterObject.h"
class ChainedScatterTable:public HashTable
{
	ChainedScatterObject* niz;
	int lrmp;

public:
	~ChainedScatterTable();
	ChainedScatterTable(int v, int k);

	void insert(int **a);
	void print();
	
};

