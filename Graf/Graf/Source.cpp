#include"Graph.h"
#include<iostream>
using namespace std;
int main()
{
	Graph g;
	int a[] = { 0,1,2,3,4 };
	g.insertNode(a[1]);
	g.insertNode(a[2]);
	g.insertNode(a[3]);
	g.insertNode(a[4]);

	g.insertEdge(a[1], a[3],3);
	g.insertEdge(a[1], a[2],2);
	g.insertEdge(a[1], a[4],10);
	g.insertEdge(a[2], a[1],4);
	g.insertEdge(a[3], a[1],6);
	g.insertEdge(a[4], a[2],9);
	g.insertEdge(a[4], a[1],10);

	g.print();

	cout << g.fly(1);
	return 0;
}