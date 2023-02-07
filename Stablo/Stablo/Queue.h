#pragma once
#include"BSTNode.h"
class Queue
{
protected:
	BSTNode** niz;
	long size;
	long head;
	long tail;
	long br;

public:
	Queue(long n);
	~Queue();

	bool isEmpty()const { return br == 0; };
	long brEl()const { return br; };

	BSTNode* getHead()const;
	void enqueue(BSTNode* el);
	BSTNode* dequeue();
};

