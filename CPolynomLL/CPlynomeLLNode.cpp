#include "CPlynomeLLNode.h"

CPolynomeLLNode::CPolynomeLLNode(int exp, double coef, CPolynomeLLNode* c)
{
	this->exp = exp;
	this->coef = coef;
	this->next = c;
}

//CPolynomeLLNode::~CPolynomeLLNode()
//{
//	if (next != nullptr)
//	{
//		delete next;
//	}
//}

ostream& operator<<(ostream& izlaz, CPolynomeLLNode t)
{
	izlaz << t.coef <<"x^"<< t.exp;
	return izlaz;
}
