#include "Graph.h"
#include"Queue.h"
#include<iostream>
using namespace std;
void Graph::setStatusForAllNodes(int status)
{
	LinkedNode* p = start;
	while (p != nullptr)
	{
		p->status = status;
		p = p->next;
	}
}
Graph::Graph()
{
	start = nullptr;
	br = 0;
}

Graph::~Graph()
{
}

LinkedNode* Graph::findNode(int& data)
{
	LinkedNode* p = start;
	while (p != nullptr && p->node != data)
	{
		p = p->next;
	}
	return p;
}

LinkedEdge* Graph::findEdge(int& dataSrc, int& dataDest)
{
	LinkedNode* p = findNode(dataSrc);
	if (p == nullptr)
	{
		return nullptr;
	}

	LinkedEdge* e = p->adj;
	while (e != nullptr && e->dest->node != dataDest)
	{
		e = e->link;
	}
	return e;
}

void Graph::insertNode(int& data)
{
	start = new LinkedNode(data, start,nullptr);
	br++;
}

bool Graph::insertEdge(int& dataSrc, int& dest, const double& w)
{
	LinkedNode* psrc = nullptr;
	LinkedNode* pdest = nullptr;
	LinkedNode* p = start;
	while (p != nullptr && (psrc == nullptr || pdest == nullptr))
	{
		if (p->node == dataSrc)
		{
			psrc = p;
		}
		else if (p->node == dest)
			pdest = p;

		p = p->next;
	}

	if (psrc == nullptr || pdest == nullptr)
	{
		return false;
	}
	psrc->adj = new LinkedEdge(pdest, psrc->adj);
	return true;
}

void Graph::print()
{
	LinkedNode* p = start;
	while (p != nullptr)
	{
		cout << p->node << "->";
		LinkedEdge* e = p->adj;
		while (e != nullptr)
		{
			cout << e->dest->node << " | ";
			e = e->link;
		}
		cout << endl;
		p = p->next;
	}
}

long Graph::breadthFirstTraversal(int& data)
{
	long retVal = 0;

	LinkedNode* p = findNode(data);
	if (p == nullptr)
	{
		return 0;
	}
	setStatusForAllNodes(1);
	Queue q(br);
	q.enqueue(p);
	p->status = 2;
	while (!q.isEmpty())
	{
		p = q.dequeue();
		p->visit();
		p->status = 3;
		retVal++;
		LinkedEdge* e = p->adj;
		while (e != nullptr)
		{
			if (e->dest->status == 1)
			{
				q.enqueue(e->dest);
				e->dest->status = 2;
			}
			e = e->link;
		}
	}
	cout << endl;
	return retVal;
}

int Graph::findPath(int a, int b, int& cvorovi)
{
	LinkedNode* p = start;
	LinkedNode* aa = nullptr;
	LinkedNode* bb = nullptr;

	while (p != nullptr)
	{
		p->status = 1;
		if (p->node == a)
		{
			aa = p;
		}
		else if (p->node == b)
			bb = p;
		p = p->next;
	}
	Queue q(br);
	p = aa;
	q.enqueue(p);
	p->status = 2;
	int duzina = 0;
	while (!q.isEmpty())
	{
		p = q.dequeue();
		p->status = 3;
		if (p == bb)
		{
			break;
		}
		LinkedEdge* e = p->adj;
		while (e != nullptr)
		{
			if (e->dest->status == 1)
			{
				e->dest->prev = p;
				q.enqueue(e->dest);
				e->dest->status = 2;
			}
			e = e->link;

		}
	}
	if (p == bb)
	{
		LinkedNode* pomocni = bb;
		LinkedNode* prethodni = pomocni;
		LinkedEdge* edz = bb->adj;

		while (pomocni != nullptr)
		{
			edz = pomocni->adj;
			while (edz != nullptr && edz->dest != prethodni)
			{
				edz = edz->link;
			}
			if (edz != nullptr)
			{
				duzina += edz->weight;
			}
			cvorovi++;
			prethodni = pomocni;
			pomocni = pomocni->prev;
		}
	}
	return duzina;
}

int Graph::findPath(int a, int b, int c, int duzina)
{
	int cvorovi = 0;
	int len1 = findPath(a, b, cvorovi);
	int cvorovi2 = 0;
	int len2 = findPath(a, c, cvorovi2);
	if (cvorovi < cvorovi2)
	{
		if (len1 < duzina)
		{
			return b;
		}
		if (len2 < duzina)
		{
			return c;
		}
		else
			return -1;
	}
	else
	{
		if (len2 < len1)
		{
			if (len2 < duzina)
			{
				return c;
			}
		}
		else
			if (len1 < duzina)
				return b;
			else
				return -1;
	}
	return 0;
}

bool Graph::CanReachMoreWithUndirected(int a)
{
	long orijentisan = breadthFirstTraversal(a);
	LinkedNode* p = start;
	while (p != nullptr)
	{
		LinkedEdge* e = p->adj;
		while (e != nullptr)
		{
			LinkedEdge* e2 = e->dest->adj;
			while (e2 != nullptr && e2->dest != p)
			{
				e2 = e2->link;
			}
			if (e2 == nullptr)
			{
				insertEdge(e->dest->node, p->node);
			}
			e = e->link;
		}
		p = p->next;
	}

	long neorijentisan = breadthFirstTraversal(a);
	if (neorijentisan > orijentisan)
	{
		return true;
	}
	return false;
}

int Graph::fly(int a)
{
	LinkedNode* p = start;
	LinkedNode* po = nullptr;

	while (p != nullptr)
	{
		p->status = 1;
		if (p->node == a)
		{
			po = p;
		}
		p = p->next;
	}
	p = po;
	Queue q(br);
	q.enqueue(p);
	p->status = 2;
	LinkedNode* u;
	while (!q.isEmpty())
	{
		p = q.dequeue();
		p->status = 3;
		LinkedEdge* e = p->adj;
		int max = 0;
		u = nullptr;
		while (e != nullptr)
		{
			if (e->weight > max && e->dest->status == 1)
			{
				max = e->weight;
				u = e->dest;
			}

			e = e->link;
		}
		if (u != nullptr)
		{
			q.enqueue(u);
			u->status = 2;
			u->prev = p;
		}

	}

	/*
		Poslednji cvor se nalazi u p i onda se vracamo
		unazad i sabiramo tezine potega(weight).
		Za dati graf:
		V = {1,2,3,4} ->CVOROVI
		E = {{1,2},{1,3},{1,4},{2,1},{3,1},{4,1},{4,2}} ->GRANE
		1.iteracija
			u = 2
			p = 4
			e->dest = u tj 2 i izlazimo odma iz petlje i sabiramo tezinu
		2.iteracija
			u = 4
			p = 1
			e->dest = 4 u 3.iteraciji ununtrasnje petlje i tu se sabira tezina
		3.iteracija
			u = 1
			p = nullptr i izlazi se iz petlje 
	*/
	u = p;
	p = p->prev;
	int val = 0;
	while (p != nullptr)
	{
		LinkedEdge* e = p->adj;
		while (e != nullptr && e->dest != u)
		{
			e = e->link;
		}
		if (e->dest == u)
		{
			val += e->weight;
		}
		u = p;
		p = p->prev;
	}
	return val;
}
