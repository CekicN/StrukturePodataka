#include"ChainedHash.h"
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	ChainedHash hes(64);
	HashObject o;
	for (int i = 2000000000; i < 2000000010; i++)
	{
		o = HashObject(i, rand() % 10 + 1);
		hes.insert(o);
	}
	hes.print();
	return 0;
}