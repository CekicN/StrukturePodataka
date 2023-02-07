#pragma once
#include"Node.h"
class DLList
{
protected:
	Node* head;
	Node* tail;

public:
	DLList() { head = tail = nullptr; }
	~DLList();

	Node* getHead() { return head; }
	bool isEmpty() { return head == nullptr; }
	void Print();
	void AddToHead(int e);
	void AddToTail(int e);
	int deleteFromHead();
	int deleteFromTail();
};

