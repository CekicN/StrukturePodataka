#pragma once
#include"BSTNode.h"
class Stack
{
protected:
	BSTNode** niz;
	long size;
	long top;

public:
	Stack(long n);
	~Stack();

	bool isEmpty() const { return top == -1; };
	long brElemenata()const { return (top + 1); };

	BSTNode* getTop()const;
	void push(BSTNode* el);
	BSTNode* pop();


};

