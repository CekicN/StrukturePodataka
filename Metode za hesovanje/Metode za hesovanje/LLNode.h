#pragma once
#include"HashObject.h"
class LLNode
{
public:
	HashObject vrednost;
	LLNode* next;

public:
	LLNode();
	LLNode(HashObject v);
	LLNode(HashObject v, LLNode* n);

	bool isEqual(int key);
	void print();

};

