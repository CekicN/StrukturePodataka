#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(int len)
{
	n = len;
	lrmp = n;
	br = 0;
	niz = new ChainedScatterObject[2 * len];
	
	for (int i = n; i < 2*n-1; i++)
	{
		niz[i].next = i+1;
	}
	niz[2 * n - 1].next = 0;
}

ChainedScatterTable::~ChainedScatterTable()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}



void ChainedScatterTable::withdraw(char* k)
{	
	if (br == 0)
	{
		throw "hes je pun";
	}
	long probe = h(k);
	long prev = -1;
	while (probe != -1 && !niz[probe].isEqual(k))
	{
		prev = probe;
		probe = niz[probe].next;
	}
	if (probe == -1)
	{
		throw "Nije nadjen";
	}
	if (prev != -1)
	{
		niz[prev].next = niz[probe].next;
		niz[probe].deleteValue();
		niz[probe].status = 1;
	}
	else
	{
		if (niz[probe].next == -1)
		{
			niz[probe].deleteValue();
			niz[probe].status = 1;
		}
		else
		{
			long nextEl = niz[probe].next;
			niz[probe].deleteValue();
			niz[probe] = niz[nextEl];
			niz[probe].next = niz[nextEl].next;
			niz[nextEl] = ChainedScatterObject();
			niz[nextEl].status = 1;

		}
		br--;
	}
}

void ChainedScatterTable::insert(ChainedScatterObject el)
{
	if (br == n)
	{
		throw "tablica je puna";
	}
	int i = h(el.getKey());
	if (niz[i].status == 2)
	{
		while (niz[i].status == 2 && niz[i].next != -1 && niz[i].next != 0)
		{
			i = niz[i].next;
		}
		if (i == 0)
		{
			throw "Prostor za sinonime je pun";
		}

		niz[i].next = lrmp;
		i = lrmp;
		lrmp = niz[i].next;
	}
	niz[i] = el;
	niz[i].status = 2;
	niz[i].next = -1;
	br++;
}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * n; i++)
	{
		if (i == n)
			std::cout << "---------------------------------------" << std::endl;
		std::cout << i << " ";
		niz[i].print();
	}
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!niz[probe].isEqual(key))
			probe = niz[probe].next;
		else
			return niz[probe];
	}
	return ChainedScatterObject();
}
