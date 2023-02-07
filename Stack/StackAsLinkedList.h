#pragma once
#include"LL.h"
template<class T>
class StackAsLinkedList
{
	LL<T> stack;

public:
	StackAsLinkedList();
	void push(T el);
	T pop();
	int BrElmenata();
	T GetTop();
	void Stampaj();
};

template<class T>
inline StackAsLinkedList<T>::StackAsLinkedList()
{
}

template<class T>
inline void StackAsLinkedList<T>::push(T el)
{
	stack.AddToHead(el);
}

template<class T>
inline T StackAsLinkedList<T>::pop()
{
	return stack.PopFromTail();
}

template<class T>
inline int StackAsLinkedList<T>::BrElmenata()
{
	return stack.getBr();
}

template<class T>
inline T StackAsLinkedList<T>::GetTop()
{
	return stack.getFromTail();
}

template<class T>
inline void StackAsLinkedList<T>::Stampaj()
{
	stack.stampaj();
}
