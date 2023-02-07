#pragma once
#include"LinkedNode.h"
class Queue
{
protected:
	LinkedNode** niz;
	long size;
	long head;
	long tail;
	long br;

public:
	Queue(long n);
	~Queue();

	bool isEmpty()const { return br == 0; };
	long brEl()const { return br; };

	LinkedNode* getHead()const;
	void enqueue(LinkedNode* el);
	LinkedNode* dequeue();
};

