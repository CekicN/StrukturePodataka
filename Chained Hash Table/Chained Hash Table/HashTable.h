#pragma once
class HashTable
{
protected:
	unsigned int n;
	unsigned int count;


	unsigned int h(char* key);
	unsigned int f(char* key);
	unsigned int g(int e);
	unsigned int gSquare(unsigned int e);
	unsigned int gFibonacci(unsigned int e);
public:
	int GetLength() { return n; }
};

