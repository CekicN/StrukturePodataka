#pragma once
#include"Red.h"
template <class T>
class RedAsArray : public Red<T>
{
	T* niz;
	int n;
	int br;
	int head;
	int tail;

public:
	RedAsArray(int n);
	~RedAsArray();

	void enqueue(T el);
	T dequeue();
	T getHead();
	bool isEmpty();
	int BrElemenata();
	void print();
};

template<class T>
inline RedAsArray<T>::RedAsArray(int n)
{
	this->n = n;
	niz = new T[n];
	br = 0;
	head = tail = -1;
}

template<class T>
inline RedAsArray<T>::~RedAsArray()
{
	if (niz != 0)
	{
		delete[] niz;
	}
}

template<class T>
inline void RedAsArray<T>::enqueue(T el)
{
	if (br == n)
	{
		throw "PUN";
	}

	if (++tail == n)
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

template<class T>
inline T RedAsArray<T>::dequeue()
{
	if (isEmpty())
	{
		throw "PRAZAN";
	}
	T b = niz[head];
	if (++head == n)
	{
		head = 0;
	}
	
	br--;
	if (br == 0)
	{
		head = tail = -1;
	}
	return b;
}

template<class T>
inline T RedAsArray<T>::getHead()
{
	if (isEmpty())
	{
		throw "PRAZAN";
	}
	return niz[head];
}

template<class T>
inline bool RedAsArray<T>::isEmpty()
{
	return br == 0;
}

template<class T>
inline int RedAsArray<T>::BrElemenata()
{
	return br;
}

template<class T>
inline void RedAsArray<T>::print()
{
	for (int i = head; i <= tail; i++)
	{
		cout << niz[i] << ", ";
	}
	cout << endl;
}
