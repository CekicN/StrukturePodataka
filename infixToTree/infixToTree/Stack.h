#pragma once
template<class T>
class Stack
{
	T* niz;
	int n;
	int top;

public:
	Stack(int n)
	{
		this->n = n;
		niz = new T[n];
		top = -1;
	}
	~Stack()
	{
		if (niz != nullptr)
		{
			delete[] niz;
		}
	}
	void push(T el)
	{
		if (top++ == n)
		{
			throw "stek je pun";
		}
		niz[top] = el;
	}

	T pop()
	{
		if (top-- == -1)
		{
			throw "stek je prazan";
		}
		T el = niz[top];
		return el;
	}
	bool isEmpty() { return top == -1; }
	T Top()
	{
		return niz[top];
	}
};

