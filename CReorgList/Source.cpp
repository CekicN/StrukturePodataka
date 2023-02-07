#include"CReorgList.h"
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	CReorgList l;
	Node n1(3);
	Node n2(5);
	Node n3(2);
	Node n4(4);
	Node n5(1);
	l.AddToTail(n1);
	l.AddToTail(n4);
	l.AddToTail(n3);
	l.AddToTail(n2);
	l.AddToTail(n5);
	
	l.stampa(); cout << endl;
	cout<<l.GetTransp(5);
	cout << endl;
	l.stampa();
	return 0;
}