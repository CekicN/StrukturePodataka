#pragma once
#include<iostream>
using namespace std;
class stek
{
	int* niz;
	int n;
	int top;
	int brel;

public:
	stek(int n);
	~stek();
	void push(int el);
	int pop();
	stek* reverse();
	stek* saberi(stek& b);
	int getBr() { return brel; }
	void print() {
		for (int i = 0; i < brel; i++)
		{
			cout << niz[i] <<" ";
		}
	}
};

