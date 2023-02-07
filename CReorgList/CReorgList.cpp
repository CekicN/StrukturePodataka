#include "CReorgList.h"

CReorgList::CReorgList()
{
	head = tail = nullptr;
}

void CReorgList::AddToTail(Node n)
{
	Node* tmp = new Node(n.key);
	if (head == nullptr)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
}

Node* CReorgList::GetToStart(int key)
{
	Node* i, *prev = nullptr;
	for (i = head; i != nullptr && i->key != key; i = i->next)
	{
		prev = i;
	}
	if (i == nullptr)
	{
		Node* nema = new Node(-1);
		return nema;
	}
	else
	{
		prev->next = i->next;
		i->next = head;
		head = i;
	}
	return i;
}

Node* CReorgList::GetTransp(int key)
{
	Node* i, * prev = nullptr, *prevprev = nullptr;
	int b = 0;
	for (i = head; i != nullptr && i->key != key; i = i->next)
	{
		if (b >= 1)
		{
			prevprev = prev;
		}
		prev = i;
		b++;
	}
	if (i == nullptr)
	{
		Node* nema = new Node(-1);
		return nema;
	}
	else if (prevprev == nullptr)
	{
		prev->next = i->next;
		i->next = head;
		head = i;
	}
	else
	{
		prev->next = i->next;
		i->next = prevprev->next;
		prevprev->next = i;
	}
	return i;
}

void CReorgList::stampa()
{
	for (Node* i = head; i != nullptr; i=i->next)
	{
		i->print();
		cout << "-->";
	}
	cout << endl;
}
