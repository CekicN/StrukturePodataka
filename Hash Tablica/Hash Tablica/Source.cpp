#include"ChainedHashTable.h"
#include<stdlib.h>
#include<time.h>
int main()
{	
	srand(time(0));
	ChainedHashTable<int, int> hes(10);
	int a;
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 10 + 1;
		HashObject<int, int> el(rand(), &a);
		hes.insert(el);
	}

	hes.print();
	return 0;
}