#include"DLList.h"

void umetniListu(DLList uredjena, DLList nova)
{
	Node* i;
	Node* k;
	Node* j = uredjena.getHead();

	//for ( i = nova.getHead(); i != nullptr; i = i->next)
	//{
	//	if (j->value > i->value)
	//	{

	//	}
	//}
	while (j->next != nullptr)
	{

		for (i = nova.getHead(); i != nullptr ; i = i->next)
		{

			if (j->next->value > i->value)
			{
				if (i->value == nova.getHead()->value)
				{
					
				}
				else
					i->prev->next = i->next;
				if (i->next != nullptr)
				{
					i->next->prev = i->prev;
				}

				i->next = j->next;
				j->next = i;
				i->prev = j;
				i->next->prev = i;

				break;

			}
		}
		j = j->next;
	}

}

int main()
{
	DLList a;
	DLList b;
	a.AddToHead(9);
	a.AddToHead(7);
	a.AddToHead(3);
	a.AddToHead(1);
	
	b.AddToHead(2);
	b.AddToHead(6);
	b.AddToHead(5);

	a.Print();
	cout << endl;
	b.Print();

	umetniListu(a, b);

	a.Print();
	return 0;
}