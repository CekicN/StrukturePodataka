#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int

	unsigned int h = 0;
	for (int i = 3; i < 7; i++)
		h += key[i];
	h += key[8];
	h += key[9];
	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodu unsigned int u [0...M-1]
	int a = 0.610833 * pow(2, 32);

	return (a*key) >> 26;
}

