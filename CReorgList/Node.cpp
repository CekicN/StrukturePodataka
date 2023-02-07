#include "Node.h"

Node::Node()
{
	next = nullptr;
}

Node::Node(int key)
{
	this->key = key;
	next = nullptr;
}

Node::Node(int key, Node* n)
{
	this->key = key;
	next = n;
}

ostream& operator<<(ostream& izlaz, const Node* n)
{
	izlaz << n->key;
	return izlaz;
}
