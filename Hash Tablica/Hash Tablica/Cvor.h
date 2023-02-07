#pragma once
#include<stddef.h>
#include<iostream>
using namespace std;
template <class T>
class Cvor
{
public:
	T info;
	Cvor<T>* next; //pokazivac na sledeceg
public:
	Cvor() { next = NULL; }
	Cvor(T i) { info = i; next = NULL; }
	Cvor(T i, Cvor<T>* n) { info = i; next = n; }
	~Cvor() {}
	void print() 
	{ 
		
			cout << info;
		
	}
	bool jednako(T el) { return el == info; }
	
	
};

