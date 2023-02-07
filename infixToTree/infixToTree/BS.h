#pragma once
#include"Stack.h"
#include"BSnode.h"
#include<string>
class BS
{
	BSnode* root;
	bool isAlpha(char i)
	{
		return (i >= '0' && i <= '9');
	}
public:
	void preorder()
	{
		preorder(root);
	}
	void preorder(BSnode* p)
	{
		if (p != nullptr)
		{
			p->visit();
			preorder(p->left);
			preorder(p->right);
		}
	}
	void postorder(BSnode* p)
	{
		if (p != nullptr)
		{
			postorder(p->left);
			postorder(p->right);
			p->visit();
		}
	}
	BSnode* infixToTree(char* izraz)
	{
		Stack<char> C(strlen(izraz));
		Stack<BSnode*> N(strlen(izraz));
		BSnode* t, * t1, * t2;


		int p[123] = { 0 };
		p[')'] = 0;
		p['+'] = p['-'] = 1;
		p['*'] = p['/'] = 2;
		p['^'] = 3;


		for (int i = 0; i < strlen(izraz); i++)
		{
			if (izraz[i] == '(')
			{
				C.push(izraz[i]);
			}
			else if (isAlpha(izraz[i]))
			{
				t = new BSnode(izraz[i]);
				N.push(t);
			}
			else if (p[izraz[i]] > 0)
			{
				while (!C.isEmpty() && C.Top() != '('
					&& ((izraz[i] != '^' && p[C.Top()] >= p[izraz[i]])
						|| (izraz[i] == '^'
							&& p[C.Top()] > p[izraz[i]])))
				{
					t = new BSnode(C.pop());

					t1 = N.pop();
					t2 = N.pop();

					t->left = t1;
					t->right = t2;

					N.push(t);
				}
				C.push(izraz[i]);
			}
			else if (izraz[i] == ')') {
				while (!C.isEmpty() && C.Top() != '(')
				{
					t = new BSnode(C.Top());
					C.pop();
					t1 = N.Top();
					N.pop();
					t2 = N.Top();
					N.pop();
					t->left = t2;
					t->right = t1;
					N.push(t);
				}
				C.pop();
			}
		}
		t = N.Top();
		return t;
		
	}
};

