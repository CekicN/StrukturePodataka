#include "BSTNode.h"

BSTNode::BSTNode()
{
	left = right = nullptr;
}

BSTNode::BSTNode(int el)
{
	key = el;
	left = right = nullptr;
}

BSTNode::BSTNode(int el, BSTNode* l, BSTNode* r)
{
	key = el;
	left = l;
	right = r;
}

bool BSTNode::isLT(int el)
{
	if (key < el)
	{
		return true;
	}
	return false;
}

bool BSTNode::isGT(int el)
{
	if (key > el)
	{
		return true;
	}
	return false;
}

 bool BSTNode::isEQ(int el)
{
	if (key == el)
	{
		return true;
	}
	return false;
}

void BSTNode::setKey(int el)
{
	key = el;
}

int BSTNode::getKey()
{
	return key;
}

void BSTNode::visit()
{
	cout << key << " ";
}
