#pragma once
#include"Node.h"
template <class T>
class LL
{
	Node<T>* head;
	Node<T>* tail;

	int br;
public:
	LL();
	~LL();

	void AddToHead(T el);
	void AddToTail(T el);
	T PopFromTail();
	T getFromTail();
	bool isEmpty() { return head == nullptr; }
	void stampaj();
	int getBr() { return br; }
};

template<class T>
inline LL<T>::LL()
{
	head = tail = nullptr;
	br = 0;
}

template<class T>
inline LL<T>::~LL()
{
	while (!isEmpty())
	{
		Node<T>* tmp = head;
		head = head->next;
		
		delete tmp;
	}
}

template<class T>
inline void LL<T>::AddToHead(T el)
{
	 head = new Node<T>(el, head);

	 if (tail == nullptr)
	 {
		 tail = head;
	 }
}

template<class T>
inline void LL<T>::AddToTail(T el)
{
	Node<T>* tmp = new Node<T>(el);
		if (!isEmpty())
		{
			tail->next = tmp;
			tail = tail->next;
		}
		else
			head = tail = tmp;
	br++;
}

template<class T>
inline T LL<T>::PopFromTail()
{
	T b = tail->info;
	Node<T>* i;
	for (i = head; i->next != tail; i = i->next);
	Node<T>* tmp = tail;
	tail = i;
	i->next = nullptr;
	delete tmp;
	br--;
	return b;
}

template<class T>
inline T LL<T>::getFromTail()
{
	return tail->info;
}

template<class T>
inline void LL<T>::stampaj()
{

	for (Node<T>* i = head; i != nullptr; i = i->next)
	{
		cout << "| " << i << " |\n";
	}
	cout << "______"<<endl;
}
