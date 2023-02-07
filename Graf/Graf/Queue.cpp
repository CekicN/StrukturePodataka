#include "Queue.h"

Queue::Queue(long n)
{
	size = n;
	niz = new LinkedNode * [n]();
	br = 0;
	head = tail = -1;
}

Queue::~Queue()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

LinkedNode* Queue::getHead() const
{
	if (isEmpty())
	{
		throw "red je prazan";
	}
	return niz[head];
}

void Queue::enqueue(LinkedNode* el)
{
	if (br == size)
	{
		throw "red je pun";
	}

	if (++tail == size)
	{
		tail = 0;
	}
	niz[tail] = el;
	if (br == 0)
	{
		head = tail;
	}
	br++;
}

LinkedNode* Queue::dequeue()
{
	if (isEmpty())
	{
		throw "red je prazan";
	}
	LinkedNode* r = niz[head];
	if (++head == size)
	{
		head = 0;
	}
	br--;
	if (br == 0)
	{
		head = tail = -1;
	}
	return r;
}
