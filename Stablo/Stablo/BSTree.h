#pragma once
#include"BSTNode.h"
#include"Stack.h"
#include"Queue.h"
class BSTree
{
protected:
	BSTNode* root;
	long numOfElements;

	void preorder(BSTNode* p)const ;
	void postorder(BSTNode* p)const ;
	void inorder(BSTNode* p)const ;
public:
	BSTree();
	~BSTree();

	void deleteTree(BSTNode* p);
	bool isEmpty() { return root == nullptr; }
	void insert(int el);

	bool isInTree(int el);
	BSTNode* search(int el);
	BSTNode* search(BSTNode* p, int el);
	void balance(int data[], int first, int last);
	void deleteByCopying(int el);
	void deleteByMerging(int el);
	void preorder();
	void postorder();
	void inorder();


	void bredthfirst();
	void iterativepreodrer();
	void iterativepostodrer();
	void iterativeinodrer();
};
