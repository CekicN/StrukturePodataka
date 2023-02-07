#pragma once
#include"LancanaLista.h"
#include"HashTable.h"
#include"HashObject.h"
#include<iostream>
using namespace std;
template<class T, class R>
class ChainedHashTable : public HashTable<T, R>
{
protected:
	LancanaLista<HashObject<T, R>>* niz;
public:
	ChainedHashTable(unsigned int len)
	{
		this->lenght = len;
		this->count = 0;
		niz = new LancanaLista<HashObject<T, R>>[len];
	}
	~ChainedHashTable()
	{
		for (unsigned int i = 0; i < this->lenght; i++)
		{
			while (!niz[i].isEmpty())
			{
				niz[i].DeleteFromHead();
			}
		}
		delete[] niz;
	}

	void insert(HashObject<T, R> obj)
	{
		niz[this->h(obj)].AddToHead(obj);
		this->count++;
	}
	void withdraw(HashObject<T, R> obj)
	{
		niz[h(obj)].DeleteEl(obj);
		this->count--;
	}
	void withdraw(T key)
	{
		HashObject<T, R> obj = find(key);
		withdraw(obj);
	}
	HashObject<T, R> find(T key)
	{
		HashObject<T, R> obj;
		unsigned int i = f(key) % this->lenght;

		obj = niz[i].GetHeadEl();
		while (!(obj.isEqualKey(key)))
		{
			obj = niz[i].GetNextEl(obj);
		}
		return obj;
	}
	void print()
	{
		HashObject<T, R> o();
		for (int i = 0; i < this->count; i++)
		{
			
				niz[i].PrintAll();
				
			
			cout << endl;
		}
	}

};

