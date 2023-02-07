#include "CPolynomLL.h"
CPolynomLL::CPolynomLL()
{
	head = nullptr;
}

CPolynomLL::CPolynomLL(const CPolynomLL& c)
{
	CPolynomeLLNode* i, *tail= nullptr, *h = nullptr;
	for ( i = c.head; i->next != nullptr; i = i->next)
	{
		CPolynomeLLNode* tmp = new CPolynomeLLNode(i->exp, i->coef);
		if (tail == nullptr)
		{
			h=tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		if (h == nullptr)
		{
			h = tail;
		}
	}
	head = h;
}

CPolynomLL::~CPolynomLL()
{
	while (!isEmpty())
	{
		CPolynomeLLNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void CPolynomLL::Coef(int exp, double coef)
{
	if (coef == 0)
	{
		return;
	}

	CPolynomeLLNode* i;
	CPolynomeLLNode* prev = nullptr;
	CPolynomeLLNode* tmp = new CPolynomeLLNode(exp, coef);
	if (isEmpty())
	{
		head = tmp;
		return;
	}


	for (i = head; i != nullptr; i = i->next)
	{
		if (i->exp == exp)
		{
			i->coef += coef;
			delete tmp;
			return;
		}
		else if(i->exp < exp)
		{
			break;
		}
		prev = i;
	}
	if (prev == head || i == nullptr)
	{
		tmp->next = head;
		head = tmp;
	}
	else if (prev == nullptr)
	{
		tmp->next = nullptr;
		i->next = tmp;
	}
	else
	{
		tmp->next = i;
		prev->next = tmp;
	}
	
}

CPolynomLL* CPolynomLL::Add(CPolynomLL poly1, CPolynomLL poly2)
{
	CPolynomLL* zbir = new CPolynomLL;
	CPolynomeLLNode* i1;
	CPolynomeLLNode* i2;
	for (i1 = poly1.head, i2 = poly2.head; i1 != nullptr && i2 != nullptr; i1 = i1->next, i2 = i2->next)
	{
		zbir->Coef(i1->exp, i1->coef);
		zbir->Coef(i2->exp, i2->coef);
	}

	while (i1 != nullptr)
	{
		zbir->Coef(i1->exp, i1->coef),
			i1 = i1->next;
	}
	while (i2 != nullptr)
	{		zbir->Coef(i2->exp, i2->coef),
		i2 = i2->next;
	}
	return zbir;
}

void CPolynomLL::stampaj()
{
	for (CPolynomeLLNode* i = head; i != nullptr; i= i->next)
	{
		i->stampa();
	}
}

bool CPolynomLL::isEmpty()
{
	return head == nullptr;
}
