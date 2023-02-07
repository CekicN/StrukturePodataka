#pragma once
#include<iostream>
using namespace std;
template <class T>
class Red
{
public:
	virtual void enqueue(T el) { throw "virtual enqueue"; }
	virtual T dequeue() { throw "virtual dequeue"; }
	virtual T getHead() { throw "virtual getHead"; }
	virtual bool isEmpty() { throw "virtual isEmpty"; }
	virtual int BrElemenata() { throw "virtual BrElemenata"; }
	virtual void print() { throw "virtual print"; }
};

