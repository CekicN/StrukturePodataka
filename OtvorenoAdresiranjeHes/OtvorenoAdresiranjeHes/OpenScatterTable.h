#pragma once
#include"HashTable.h"
#include"ScatterObject.h"
class OpenScatterTable:public HashTable
{
	ScatterObject* niz;

public:
	OpenScatterTable(int M, int N, int Z);
	~OpenScatterTable();

	unsigned int c(int i);

	unsigned int findUnoccupied(ScatterObject o);
	unsigned int findMatch(int x,int y, int z);
	ScatterObject find(int x, int y, int z);
	void insert(ScatterObject el);
	void print();
};

