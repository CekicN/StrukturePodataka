#pragma once
#include<stdlib.h>
#include<time.h>
template<class T>
class MultiDimensional
{
protected:
	T* data;
	long* dim;
	long* fact;
	int dimension;
	long n;
	long getOffset(long* indices, int n);
	
public:
	MultiDimensional(long* args, int n);
	inline T& getAt(long* indices, int n) { return data[getOffset(indices, n)]; }
	inline void setAt(T obj, long* indices, int n) { data[getOffset(indices, n)] = obj; }
	inline int getN() { return n; }
	T obilazak(long d, long g);
	void randUnos();
	
};

template<class T>
inline long MultiDimensional<T>::getOffset(long* indices, int n)
{
	if (n != dimension)
	{
		throw ("Broj dimenzija netacan");
	}
	long offset = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (indices[i] < 0 || indices[i] >= dim[i])
		{
			throw "Indeks je van granica";
		}
		offset += fact[i] * indices[i];
	}
	return offset;
}

template<class T>
inline T MultiDimensional<T>::obilazak(long d, long g)
{
	T s = 0;
	if (d>=g)
	{
		throw "lose granice!!!";
	}
	else
	{
		
		long k = d;
		while (k <= g)
		{
			s += data[k];

			k++;
		}
	}
	return s;
}

template<class T>
inline void MultiDimensional<T>::randUnos()
{
	srand(time(NULL));
	for (int i = 0; i <	n; i++)
	{
		data[i] = rand() % 10 + 1;
	}
}

template<class T>
inline MultiDimensional<T>::MultiDimensional(long* args, int n)
{
	dimension = n;

	dim = new long[n];
	fact = new long[n];
	long product = 1;
	for (int  i = n-1; i >= 0; --i)
	{
		dim[i] = args[i];
		fact[i] = product;
		product *= dim[i];
	}
	data = new T[product];
	this->n = product;
}
