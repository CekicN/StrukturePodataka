#include "DLList.h"

DLList::~DLList()
{
	while (!isEmpty())
	{
		deleteFromHead();
	}
	
}

void DLList::Print()
{
	for (Node* i = head; i != nullptr; i = i->next)
	{
		i->print();
		cout << "->";
	}
}

void DLList::AddToHead(int e)
{
	if (!isEmpty())
	{
		head = new Node(e, head, nullptr);
		head->next->prev = head;
	}
	else
	{
		head = tail = new Node(e);
	}
}

void DLList::AddToTail(int e)
{
	if (!isEmpty())
	{
		tail = new Node(e, nullptr, tail);
		tail->prev->next = tail;
	}
}

int DLList::deleteFromHead()
{
	if (isEmpty())
	{
		throw "Prazna";
	}
	int a = head->value;
	Node* tmp = head;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
		head->prev = nullptr;
	}
	delete tmp;
	return a;
}

int DLList::deleteFromTail()
{
	if (isEmpty())
	{
		throw " prazna";
	}

	int a = tail->value;
	Node* tmp = tail;
	if (head == tail)
	{
		head = tail = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	delete tmp;
	return a;
}

