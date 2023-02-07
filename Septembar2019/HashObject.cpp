#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	tablica = NULL;
	placen = false;
	vreme = -1;
}

HashObject::HashObject(char* t, int v, bool p)
{
	tablica = new char[strlen(t) + 1];
	strcpy(tablica, t);
	placen = p;
	vreme = v;
}

HashObject::~HashObject()
{
	if (tablica)
		delete[] tablica;
}

HashObject::HashObject(HashObject const& obj)
{
	tablica = strcpy(new char[strlen(obj.tablica) + 1], obj.tablica);
	vreme = obj.vreme;
	placen = obj.placen;
	
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (tablica)
			delete tablica;
		tablica = new char[strlen(obj.tablica) + 1];
		strcpy(tablica, obj.tablica);
		placen = obj.placen;
		vreme = obj.vreme;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->tablica, obj.tablica) == 0) && vreme == obj.vreme && placen;
}

void HashObject::deleteRecord() {
	vreme = -1;
	placen = false;
}

void HashObject::print()
{
	if(tablica!=NULL)
	{ 
		cout << tablica;
	}
		cout << "|" << vreme << " | " << placen;
	cout << endl;
}