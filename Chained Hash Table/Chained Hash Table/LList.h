#pragma once
#include"LLNode.h"
class LList
{
protected:
	LLNode* head;

public:
	LList();
	~LList();

	bool isEmpty();
	void addToHead(HashObject el);
	void addToTail(HashObject el);
	HashObject deleteFromHead();
	HashObject deleteFromTail();
	LLNode* findNodePtr(char* key);
	LLNode* getHead();
	LLNode* getNext(LLNode* ptr);
	HashObject getHeadEl();
	HashObject getNextEl(char* key);
	void printAll();
	bool isInList(char* key);
	void deleteEl(char* key);
	LLNode* removeNodeFromHead();
};

