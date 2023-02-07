#include "ChainedHash.h"

ChainedHash::ChainedHash(int len)
{
	niz = new LList[len];
	n = len;
	br = 0;
}

ChainedHash::~ChainedHash()
{
	for ( int i = 0; i < this->n;  i++)
	{
		while (!niz[i].isEmpty())
		{
			niz[i].deleteFromHead();
		}
	}
	delete[] niz;
}

void ChainedHash::insert(HashObject el)
{
	niz[h(el.key)].AddtoHead(el);
}

void ChainedHash::withdraw(HashObject el)
{
	niz[h(el.key)].deleteEl(el.key);
}

void ChainedHash::withdraw(int key)
{
	HashObject el = find(key);
	withdraw(el);
}

HashObject ChainedHash::find(int key)
{
	LLNode* i = niz[h(key)].GetHead();
	while (i != nullptr && !i->isEqual(key))
	{
		i = i->next;
	}
	if (i != nullptr)
	{
		return i->vrednost;
	}
	return HashObject();
}

void ChainedHash::print()
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "[" << i << "]" << "-->";
		niz[i].PrintAll();
	}
}
