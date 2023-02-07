#include"LancanaLista.h"

int main()
{
	LancanaLista<int> lista;
	lista.AddToHead(5);
	lista.AddToTail(10);
	lista.AddToHead(7);
	lista.AddToHead(25);

	cout<<lista.FindCvorPtr(5)<<endl;
	lista.PrintAll();
	return 0;
}