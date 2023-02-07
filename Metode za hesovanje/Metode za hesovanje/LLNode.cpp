#include "LLNode.h"

LLNode::LLNode()
{
	next = nullptr;
}

LLNode::LLNode(HashObject v)
{
	this->vrednost = v;
	next = nullptr;
}

LLNode::LLNode(HashObject v, LLNode* n)
{
	vrednost = v;
	next = n;
}

bool LLNode::isEqual(int key)
{
	return vrednost.key == key;
}

void LLNode::print()
{
	vrednost.print();
}
