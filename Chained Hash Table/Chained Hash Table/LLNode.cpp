#include "LLNode.h"

LLNode::LLNode()
{
	next = nullptr;
}

LLNode::LLNode(HashObject info)
{
	this->info = info;
	next = nullptr;
}

LLNode::LLNode(HashObject info, LLNode* n)
{
	this->info = info;
	next = n;
}

LLNode::~LLNode() {}

void LLNode::print()
{
	info.print();
}

bool LLNode::isEqual(char* key)
{
	return this->info.isEqualKey(key);
}
