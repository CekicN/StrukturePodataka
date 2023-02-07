#pragma once
#include<iostream>
using namespace std;
class BSTNode
{
public:
	int key;
	BSTNode* left, * right;
public:
	BSTNode();
	BSTNode(int el);
	BSTNode(int el, BSTNode* l, BSTNode* r);

	bool isLT(int el);
	bool isGT(int el);
	bool isEQ(int el);

	void setKey(int el);
	int getKey();
	void visit();
};

