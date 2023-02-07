#include "Node.h"

Node::Node()
{
	next = nullptr;
	prev = nullptr;
}

Node::Node(int v)
{
	value = v;
	next = nullptr;
	prev = nullptr;
}

Node::Node(int v,Node* n, Node* p)
{
	value = v;
	next = n;
	prev = p;
}

Node::Node(const Node& o)
{
	value = o.value;
	next = o.next;
	prev = o.prev;
}

void Node::print()
{
	cout << value;
}
