#pragma once
#include<iostream>
using namespace std;
#include"Stack.h"
template<class T>
class StackAsArray
{
protected:
	T* niz;
	int n;
	int top;


public:
	StackAsArray(int n);
	~StackAsArray();
	T getTop();
	void push(T el);
	T pop();
	bool isEmpty();
	int brElemenata();
	void stampaj();
};

template<class T>
inline StackAsArray<T>::StackAsArray(int n)
{
	this->n = n;
	niz = new T[this->n];
	top = -1;
}

template<class T>
inline StackAsArray<T>::~StackAsArray()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline T StackAsArray<T>::getTop()
{
	if (isEmpty())
		throw "Stack je prazan";
	return niz[top];
}

template<class T>
inline void StackAsArray<T>::push(T el)
{
	if (top == n - 1)
	{
		throw "stack je pun";
	}
	niz[++top] = el;
}

template<class T>
inline T StackAsArray<T>::pop()
{
	if (isEmpty())
		throw "stack je prazan";
	int b = niz[top--];
	return b;
}

template<class T>
inline bool StackAsArray<T>::isEmpty()
{
	return top == -1;
}

template<class T>
inline int StackAsArray<T>::brElemenata()
{
	return top+1;
}

template<class T>
inline void StackAsArray<T>::stampaj()
{
	if (isEmpty())
	{
		throw "stack je prazan";
	}
	for (int i = top; i >= 0; i--)
	{
		cout << "| " << niz[i] << " |\n";
	}
	cout << "_______" << endl;
}
