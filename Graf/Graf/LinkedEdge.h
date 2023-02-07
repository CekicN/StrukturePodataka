#pragma once

class LinkedNode;
class LinkedEdge
{
public:
	LinkedNode* dest;
	LinkedEdge* link;
	double weight;

	LinkedEdge();
	LinkedEdge(LinkedNode* d, LinkedEdge* l);
	LinkedEdge(LinkedNode* d, LinkedEdge* l, double w);
};

