#pragma once
#include"Node.h"
class CReorgList
{
	Node* head;
	Node* tail;

public:
	CReorgList();
	void AddToTail(Node n);
	Node* GetToStart(int key);
	Node* GetTransp(int key);
	void stampa();
};

