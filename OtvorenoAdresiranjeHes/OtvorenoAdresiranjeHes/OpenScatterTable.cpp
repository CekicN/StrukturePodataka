#include "OpenScatterTable.h"

OpenScatterTable::OpenScatterTable( int M, int N, int Z)
{
	n = M*N*Z;
	br = 0;
	niz = new ScatterObject[n];
	this->M = M;
	this->N = N;
	this->P = Z;
}
OpenScatterTable::~OpenScatterTable()
{
	if(niz != nullptr)
		delete[] niz;
}
unsigned int OpenScatterTable::findUnoccupied(ScatterObject o)
{
	unsigned int hash = h(o.getX(),o.getY(), o.getZ());
	unsigned int i = hash;
	if (niz[i].status < 2)
	{
		return i;//Ako je slobodan vrati;
	}
	int j = 1;

	do
	{
		i = (hash + c(j))%n;
		if (niz[i].status < 2)
		{
			return i;
		}
		j++;
	} while (i != hash && j<n);
	return 0;
}
unsigned int OpenScatterTable::findMatch(int x, int y, int z)
{
	unsigned int i = h(x,y,z);
	int hash = i;
	for (unsigned int j = 0; j < n; j++)
	{
		i = hash + c(j);
		if (niz[i].status == 0)
		{
			return -1;
		}
		if (niz[i].isEqual(x,y,z))
		{
			return i;
		}
	}
	return 0;
}

ScatterObject OpenScatterTable::find(int x, int y, int z)
{
	unsigned int i = findMatch(x,y,z);
	if (i != ~0U)
	{
		return niz[i];
	}
	else
		return ScatterObject();
}
unsigned int OpenScatterTable::c(int i)
{
	return i * i;
}

void OpenScatterTable::insert(ScatterObject el)
{
	unsigned int offset = findUnoccupied(el);
	if (el.getRecord() != 0)
	{
		niz[offset] = el;
		niz[offset].status = 2;
		br++;
	}
}

void OpenScatterTable::print()
{
	for (int i = 0; i < n; i++)
	{
		std::cout << i << "|";
		niz[i].print();
		std::cout << std::endl;
	}

}
