#pragma once
#include"CPlynomeLLNode.h"
class CPolynomLL
{
	CPolynomeLLNode* head;
public:
	CPolynomLL();
	CPolynomLL(const CPolynomLL&);
	
	~CPolynomLL();

	void Coef(int exp, double coef);
	CPolynomLL* Add(CPolynomLL poly1, CPolynomLL poly2);
	void stampaj();

	bool isEmpty();
};

