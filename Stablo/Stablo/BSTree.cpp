#include "BSTree.h"
using namespace std;
BSTree::BSTree()
{
	root = nullptr;
	numOfElements = 0;
}

BSTree::~BSTree()
{
	if (root != nullptr)
		delete[] root;
}

void BSTree::deleteTree(BSTNode* p)
{
	if (p != nullptr)
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
	}
}

void BSTree::insert(int el)
{
	BSTNode* p = root;
	BSTNode* prev = nullptr;

	//Trazi mesto za umetanje elementa
	while (p != nullptr)
	{
		prev = p;
		if (p->isLT(el))
		{
			p = p->right;
		}
		else
			p = p->left;
	}
	if (root == nullptr)
	{
		root = new BSTNode(el);
	}
	else if (prev->isLT(el))
	{
		prev->right = new BSTNode(el);
	}
	else
		prev->left = new BSTNode(el);
	numOfElements++;
}

bool BSTree::isInTree(int el)
{
	BSTNode* p = root;
	while (p != nullptr && !p->isEQ(el))
	{
		if (p->isLT(el))
		{
			p = p->right;
		}
		else
			p = p->left;
	}
	if (p != nullptr)
	{
		return true;
	}
	return false;
}

BSTNode* BSTree::search(int el)
{
	return search(root, el);
}

BSTNode* BSTree::search(BSTNode* p, int el)
{
	while (p != nullptr)
	{
		if (p->isEQ(el))
		{
			return p;
		}
		else if (p->isLT(el))
		{
			p = p->right;
		}
		else
			p = p->left;
	}
	
	return nullptr;
}

void BSTree::balance(int data[], int first, int last)
{

}

void BSTree::deleteByCopying(int el)
{
	BSTNode* node, * p = root, * pre = nullptr;

	while (p != nullptr && !p->isEQ(el))
	{
		pre = p;
		if (p->isLT(el))
		{
			p = p->right;
		}
		else
			p = p->left;
	}

	node = p;

	if (p != nullptr && p->isEQ(el))
	{
		if (node->right == nullptr)//ako ima samo levi potomak
		{
			node = node->left;
		}
		else if (node->left == nullptr)//ako ima samo desni potomak
		{
			node = node->right;
		}
		else//ako ima oba potomka
		{
			BSTNode* tmp = node->left;
			BSTNode* parent = node;
			while (tmp->right != nullptr)
			{
				parent = tmp;
				tmp = tmp->right;
			}
			node->setKey(tmp->getKey());
			if (parent == node)
			{
				parent->left = tmp->left;
			}
			else
			{
				parent->right = tmp->right;
			}
			delete tmp;
			numOfElements--;
			return;
		}
		if (p == root)
		{
			root = node;
		}
		else if (pre->left == p)
		{
			pre->left = node;
		}
		else
			pre->right = node;
		delete p;
		numOfElements--;
	}
	else if (root != nullptr)
	{
		throw "Element nije u stablu";
	}
	else
		throw "stablo je prazno";
}

void BSTree::deleteByMerging(int el)
{
	BSTNode* node, * p = root, * prev = nullptr;

	while (p != nullptr && !p->isEQ(el))
	{
		prev = p;
		if (p->isLT(el))
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}

	node = p;

	if (p != nullptr && p->isEQ(el))
	{
		if (node->right == nullptr)
		{
			node = node->left;
		}
		else if (node->left == nullptr)
		{
			node = node->right;
		}
		else
		{
			BSTNode* tmp = node->left;
			while (tmp->right != nullptr)
			{
				tmp = tmp->right;
			}
			tmp->right = node->right;
			node = node->left;
		}
		if (p == root)
		{
			root = node;
		}
		else if (prev->left == p)
		{
			prev->left = node;
		}
		else
			prev->right = node;
		delete p;
		numOfElements--;
	}
	else if (root != nullptr)
	{
		throw "Element nije u stablu";
	}
	else
		throw "stablo je prazno";
}

void BSTree::preorder()
{
	preorder(root);
}

void BSTree::postorder()
{
	postorder(root);
}

void BSTree::inorder()
{
	inorder(root);
}

void BSTree::preorder(BSTNode* p)const
{
	if (p != nullptr)
	{
		p->visit();
		preorder(p->left);
		preorder(p->right);
	}
}

void BSTree::postorder(BSTNode* p)const 
{
	if (p != nullptr)
	{
		inorder(p->left);
		inorder(p->right);
		p->visit();
	}
}

void BSTree::inorder(BSTNode* p)const 
{
	if (p != nullptr)
	{
		inorder(p->left);
		p->visit();
		inorder(p->right);
	}
}

void BSTree::bredthfirst()
{

}

void BSTree::iterativepreodrer()
{
	BSTNode* p = root;
	Stack stack(numOfElements);
	if (p != nullptr)
	{
		stack.push(p);
		while (!stack.isEmpty())
		{
			p = stack.pop();
			p->visit();
			if (p->right != nullptr)
			{
				stack.push(p->right);
			}
			if (p->left != nullptr)
			{
				stack.push(p->left);
			}
		}
	}
}

void BSTree::iterativepostodrer()
{

}

void BSTree::iterativeinodrer()
{
}
