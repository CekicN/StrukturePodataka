#pragma once
template<class T>
class Niz
{
protected:
	T* pod;
	long poc;
	unsigned long n;
	
public:
	Niz(long n);
	~Niz();

	inline void Set(T element, long i);
	inline T Get(long i);
	
	T& operator[](long i);
	
};


template<class T>
inline Niz<T>::Niz(long n)
{
	this->n = n;
	this->poc = 0;

	pod = new T[n];
}

template<class T>
inline Niz<T>::~Niz()
{
	if (pod != 0)
	{
		delete[] pod;
	}
}

template<class T>
inline void Niz<T>::Set(T element, long i)
{
	pod[i] = element;
}

template<class T>
inline T Niz<T>::Get(long i)
{
	return pod[i];
}

template<class T>
inline T& Niz<T>::operator[](long i)
{
	if (i - poc >= n)
	{
		throw "Prekoraccenje!!";
	}
	else
	{
		return pod[i];
	}
	
}
