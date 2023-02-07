#include "ChainedHashTAble.h"

ChainedHashTable::ChainedHashTable(unsigned int len)
{
	n = len;
	count = 0;
	niz = new LList[len];
}

ChainedHashTable::~ChainedHashTable()
{
	for (int i = 0; i < n; i++)
	{
		while (!niz[i].isEmpty())
		{
			niz[i].deleteFromHead();
		}
	}
	delete[] niz;
}

void ChainedHashTable::insert(HashObject obj)
{
	niz[h(obj.GetKey())].addToHead(obj);
}

void ChainedHashTable::withdraw(HashObject obj)
{
	niz[h(obj.GetKey())].deleteEl(obj.GetKey());
}

void ChainedHashTable::withdraw(char* key)
{
	HashObject o = find(key);
	withdraw(o);
}

HashObject ChainedHashTable::find(char* key)
{
	HashObject obj;
	unsigned int i = f(key) % n;
	LLNode* node = niz[i].getHead();
	while (node && !(node->info.isEqualKey(key)))
		node = node->next;
	if (node)
		return node->info;
	else
		return HashObject();

}

void ChainedHashTable::print()
{
	for (unsigned int i = 0; i < n; i++)
	{
		cout << "[" << i << "]->";
		this->niz[i].printAll();
	}
}
