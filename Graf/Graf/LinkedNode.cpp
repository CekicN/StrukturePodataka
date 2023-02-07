#include "LinkedNode.h"
#include<iostream>
using namespace std;
LinkedNode::LinkedNode()
	:node(), adj(nullptr), next(nullptr), status()
{
}

LinkedNode::LinkedNode(int n)
	: node(n), adj(nullptr), next(nullptr), status()
{
}

LinkedNode::LinkedNode(int n, LinkedNode* ne, LinkedEdge* ad)
	: node(n), adj(ad), next(ne), status()
{
}

LinkedNode::LinkedNode(int n, LinkedNode* ne, LinkedEdge* ad, int s)
	: node(n), adj(ad), next(ne), status(s)
{
}

void LinkedNode::visit()
{
	cout << node << " ";
}
