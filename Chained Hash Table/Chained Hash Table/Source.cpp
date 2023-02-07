
#include"ChainedHashTAble.h"

int main()
{
	ChainedHashTable tablica(64);
	char jmbg[] = "29079827500519999999";
	char ime[] = "Nikola Davidovic";
	HashObject o(jmbg, ime);
	tablica.insert(o);
	char jmbg2[] = "2706985730058";
	char ime2[] = "Pera Peric";
	HashObject o1(jmbg2, ime2);
	HashObject o2(jmbg, ime);
	char jmbg3[] = "2907982750052";
	char ime3[] = "Nikola Cekic";
	HashObject o3(jmbg3, ime3);
	tablica.insert(o3);
	tablica.insert(o3);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();
	
	return 0;
}