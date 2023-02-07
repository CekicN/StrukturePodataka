#pragma once
#include"LLNode.h"
class LList
{
public:
	LLNode* head;
public:
	LList();
	~LList();

	void AddtoHead(HashObject el);
	void deleteFromHead();
	void deleteEl(int key);

	LLNode* GetHead();
	HashObject GetHeadEl();
	HashObject GetEl(int key);
	LLNode* GetNode(int key);
	void PrintAll();

	bool isEmpty() { return head == nullptr; }

};

