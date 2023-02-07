#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable tablica(64);
	ScatterObject o("PK-023-PM",14,false);
	ScatterObject o1("PK-048-ZF",17,true);
	ScatterObject o2("PK-027-CB",06,false);
	ScatterObject o3("NI-067-AC",06,true);

	tablica.insert(o);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o3);

	tablica.print();

	cout<<tablica.isVisited("PK-048-ZF");
	cout<<tablica.hasPaid("NI-067-AC");
	tablica.updatePaid("PK-027-CB", true);
	
	tablica.print();
}