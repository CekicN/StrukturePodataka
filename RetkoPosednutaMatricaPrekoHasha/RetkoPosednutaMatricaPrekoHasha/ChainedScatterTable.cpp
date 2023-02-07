#include "ChainedScatterTable.h"

ChainedScatterTable::~ChainedScatterTable()
{
	if (niz != 0)
	{
		delete[] niz;
	}
}

ChainedScatterTable::ChainedScatterTable(int v, int k)
{
	this->n = v * k;
	this->lrmp = n;
	this->k = k;
	br = 0;
	niz = new ChainedScatterObject[3 * n];

	for (int i = n; i < 3*n-1; i++)
	{
		niz[i].next = i + 1;
	}
	niz[3 * n - 1].next = 0;
}

void ChainedScatterTable::insert(int **a)
{
	int probe,i,j;
	for (i = 0; i < n/k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (a[i][j] != 0)
			{
				probe = f(i, j);
				if (niz[probe].status == 2)
				{
					while (niz[probe].status == 2 && niz[probe].next != -1 && niz[probe].next != 0)
					{
						probe = niz[probe].next;
					}

					if (probe == 0)
					{
						throw "Prostor za sinpnime je pun";
					}
					niz[probe].next = lrmp;
					probe = lrmp;
					lrmp = niz[probe].next;
				}
				niz[probe] = ChainedScatterObject(i, j, a[i][j]);
				niz[probe].status = 2;
				niz[probe].next = -1;
				br++;
			}
		}
		
	}
}

void ChainedScatterTable::print()
{
	for (int i = 0; i < 2*n; i++)
	{
		if (i == n)
		{
			std::cout << "------------------------------------" << std::endl;
		}
		std::cout << i << "| ";
		niz[i].print();
	}
}
