#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node();
	Node(int v);
	Node(int v,Node* n, Node* p);
	Node(const Node& o);

	bool isEqual(int v) { return v == value; }
	void print();
};

