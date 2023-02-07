#pragma once
#include"HashObject.h"
class LLNode
{
public:
	HashObject info;
	LLNode *next;
public:
	LLNode();
	LLNode(HashObject info);
	LLNode(HashObject info, LLNode* n);
	~LLNode();

	void print();
	bool isEqual(char* key);
};

