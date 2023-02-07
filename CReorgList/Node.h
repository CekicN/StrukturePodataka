#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int key;
	//int info;
	Node* next;
public:
	Node();
	Node(int key);
	Node(int key, Node* n);
	~Node() {}

	void print()
	{
		cout << key;
	}
	friend ostream& operator<<(ostream& izlaz, const Node* n);
};

