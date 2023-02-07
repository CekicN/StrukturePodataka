#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* tablica;
	int vreme;
	bool placen;

public:
	HashObject();
	HashObject(char* t, int v, bool p);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return tablica; }
	int getVreme() { return vreme; }
	bool getPlacen() { return placen; }
	void setPlacen(bool p) { placen = p; }
	bool isEqualKey(char* k) { 
		if (k != NULL)
		{
			return strcmp(tablica, k) == 0;
		}
		else
			return false;
	}
	void print();
};