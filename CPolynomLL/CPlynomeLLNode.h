#pragma once
#include<iostream>
using namespace std;
class CPolynomeLLNode
{
public:
	CPolynomeLLNode* next;
	int exp;
	double coef;

public:
	CPolynomeLLNode(int exp , double coef, CPolynomeLLNode*  c = nullptr);
	//~CPolynomeLLNode();
	friend ostream& operator<<(ostream& izlaz, CPolynomeLLNode t);
	void stampa()
	{
		cout << coef << "x^" << exp<<" ";
	}
};

