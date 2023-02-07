#pragma once
class HashTable
{
protected:
	unsigned int n;
	unsigned int br;
public:
	unsigned int h(char* k);
	unsigned int f(char* k);
	unsigned int g(unsigned int k);
};

