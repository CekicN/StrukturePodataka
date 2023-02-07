#pragma once
template <class T>
class Stack
{
public:
	virtual T getTop() { throw "virual getTop"; }
	virtual void push(T el) { throw "virtual push"; }
	virtual T pop() { throw "virtual pop"; }
	virtual bool isEmpty() { return true; }
	virtual int brElemenata() { return 0; }
	virtual void stampaj() { throw "virtual stampaj"; }

};

