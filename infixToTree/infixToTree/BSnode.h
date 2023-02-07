#pragma once
#include<iostream>
using namespace std;
class BSnode
{
public:
	char vrednost;
	BSnode* left, * right;

	BSnode()
	{
		left = right = nullptr;
	}
	BSnode(char e)
	{
		vrednost = e;
		left = right = nullptr;
	}
	BSnode(char e, BSnode* l, BSnode* r)
	{
		vrednost = e;
		left = l;
		right = r;
	}

	void visit()
	{
		cout << vrednost << " ";
	}
};

