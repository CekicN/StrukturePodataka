#pragma once
#include"LinkedEdge.h"
class LinkedNode
{
public:
	int node;
	LinkedNode* next;
	LinkedEdge* adj;
	LinkedNode* prev;
	int status;

	LinkedNode();
	LinkedNode(int n);
	LinkedNode(int n, LinkedNode* ne, LinkedEdge* ad);
	LinkedNode(int n, LinkedNode* ne, LinkedEdge* ad, int s);

	void visit();
};

