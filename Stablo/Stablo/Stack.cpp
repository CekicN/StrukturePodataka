#include "Stack.h"

Stack::Stack(long n)
{
	size = n;
	niz = new BSTNode * [n]();
	top = -1;
}

Stack::~Stack()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

BSTNode* Stack::getTop() const
{
	if (isEmpty())
	{
		throw "stack is empty";
	}
	return niz[top];
}

void Stack::push(BSTNode* el)
{
	if (top+1 == size)
	{
		throw "Stack is full";
	}
	niz[++top] = el;

}

BSTNode* Stack::pop()
{
	if (isEmpty())
	{
		throw "stack is empty!!!";
	}
	return niz[top--];
}
