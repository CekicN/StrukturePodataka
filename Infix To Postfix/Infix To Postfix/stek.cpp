#include "stek.h"

stek::stek(int n)
{
	this->n = n;
	brel = 0;
	top = -1;
	niz = new int[n];
}

stek::~stek()
{
	if (niz != 0)
	{
		delete[] niz;
	}
}

void stek::push(int el)
{
	if (top == n - 1)
	{
		throw "stek je pun";
	}

	niz[++top] = el;
	brel++;

}

int stek::pop()
{
	if (brel == 0)
	{
		return 0;
	}

	int b = niz[top--];
	brel--;
	return b;
}

stek* stek::reverse()
{
	stek* b = new stek(n);
	for (int i = top; i > -1; i--)
	{
		b->push(niz[i]);
	}
	return b;
}

stek* stek::saberi(stek& b)
{
	int p;
	int o = 0;
	stek* rez = new stek(n + b.n);
	p = pop() + b.pop() + o;
	rez->push(p % 10);
	o = p / 10;
	while (top != -1 && b.top != -1)
	{
		p = pop() + b.pop() + o;
		rez->push(p % 10);
		o = p / 10;
	}
	while (top != -1)
	{
		p = pop() + o;
		rez->push(p % 10);
		o = p / 10;
	}

	while (b.top != -1)
	{
		p = b.pop() + o;
		rez->push(p);
		o = p / 10;
	}
	return rez;
}
