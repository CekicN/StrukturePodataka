#pragma once
class HashTable
{
protected:
	int n;
	int br;
	int M;
	int N;
	int P;
public:
	unsigned int h(int x,int y, int z);
	unsigned int f(int x, int y, int z);//za pretvaranje u unsigned int 
	unsigned int g(int k);
};

