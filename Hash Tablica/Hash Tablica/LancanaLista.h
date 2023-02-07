#pragma once
#include"Cvor.h"
#include"HashObject.h"
#include<iostream>
using namespace std;
template <class T>
class LancanaLista
{
protected:
	Cvor<T>* head, * tail;
public:
	LancanaLista() { head = tail; tail = NULL; }
	~LancanaLista();
	bool isEmpty() { return head == NULL; }
	void AddToHead(T el);
	void AddToTail(T el);
	T DeleteFromHead();
	T DeleteFromTail();
	Cvor<T>* FindCvorPtr(T el);
	Cvor<T>* GetHead() { return head; }
	Cvor<T>* GetNext(Cvor<T>* ptr);

	T GetHeadEl();
	T GetNextEl(T el);
	void PrintAll();
	bool isInList(T el);
	void DeleteEl(T el);
};

template<class T>
inline LancanaLista<T>::~LancanaLista()
{
	while (!isEmpty())
	{
		T tmp = DeleteFromHead();
	}
}

template<class T>
inline void LancanaLista<T>::AddToHead(T el)
{
	head = new Cvor<T>(el, head); //Poziva se konstruktor i kreira se Cvor [el|head] on ukazuje na isto sto i head tj prvi element liste. Kako je head promenio link na noci cvor?
	if (tail == NULL) tail = head;

}

template<class T>
inline void LancanaLista<T>::AddToTail(T el)
{
	if (!isEmpty())
	{
		tail->next = new Cvor<T>(el);
		tail = tail->next;
	}
	else
		head = new Cvor<T>(el);
}

template<class T>
inline T LancanaLista<T>::DeleteFromHead()
{
	if (isEmpty())
	{
		throw "Lista je prazna!!!";
	}
	T el = head->info;
	Cvor<T>* tmp = head;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head->next;
	}
	delete tmp;
	return el;
}

template<class T>
inline T LancanaLista<T>::DeleteFromTail()
{
	if (isEmpty())
	{
		throw ("Lista je prazna!!!");
	}
	T el = tail->info;
	Cvor<T>* tmp = tail;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		Cvor<T>* i;
		for (i = head; i->next != tail; i = i->next);
		tail = i;
		tail->next = NULL;
	}
	delete tmp;
	return el;
}

template<class T>
inline Cvor<T>* LancanaLista<T>::FindCvorPtr(T el)
{
	if (isEmpty())
		throw ("Lista je prazna!!!");
	Cvor<T>* tmp;
	for (Cvor<T>* i = head; i->next != NULL; i = i->next)
	{
		if (i->jednako(el))
		{
			tmp = i;
		}
		else
			tmp = NULL;
	}
	return tmp;
}

template<class T>
inline Cvor<T>* LancanaLista<T>::GetNext(Cvor<T>* ptr)
{
	if (isEmpty())
	{
		throw ("Lista je prazna!!");
	}
	else if (head == tail)
		throw ("Lista ima jedan element!!");
	else if (tail == ptr)
		throw ("Poslednji element nema sledbenika!!");
	Cvor<T>* i;
	for (i = head; i != NULL && i != ptr; i = i->next);
	return i->next;
}

template<class T>
inline T LancanaLista<T>::GetHeadEl()
{
	return head->info;
}

template<class T>
inline T LancanaLista<T>::GetNextEl(T el)
{
	if (isEmpty() || head == tail)
	{
		throw ("Lista je prazna ili ima samo jedan element pa nema sledbenika!!!");
	}
	else if (tail->jednako(el))
	{
		throw ("Poslednji element u listi nema svog sledbenika!!!");
	}
	Cvor<T>* i;
	for (i = head; i != NULL && i->jednako(el); i = i->next);
	if (i != NULL)
	{
		i = i->next;
	}
	return i->info;
}


template<class T>
inline void LancanaLista<T>::PrintAll()
{
	
	for (Cvor<T>* i = head; i != nullptr; i = i->next)
	{
		i->print();
		cout << " ";
	}
}

template<class T>
inline bool LancanaLista<T>::isInList(T el)
{
	if (isEmpty())
	{
		throw "Lista je prazna!!";
	}
	Cvor<T>* i;
	for (i = head; i != NULL && i->jednako(el); i = i->next);
	if (i != NULL)
	{
		return true;
	}
	return false;
}

template<class T>
inline void LancanaLista<T>::DeleteEl(T el)
{
	if (isEmpty())
	{
		throw ("Lista je prazna!!!");
	}
	if (head == tail && head->jednako(el))
	{
		delete head;
		head = tail = NULL;
	}
	else if (head->jednako(el))
	{
		Cvor<T>* tmp = head;
		head = head->next;
		delete tmp;
	}
	else
	{
		Cvor<T>* prev, * tmp;
		for (prev = head, tmp = head->next; tmp != NULL && !(tmp->jednako(el)); prev = prev->next, tmp = tmp->next);
		if (tmp != NULL)
		{
			prev->next = tmp->next;
			if (tmp == tail)
			{
				tail = prev;
			}
			delete tmp;
		}
	}

}
