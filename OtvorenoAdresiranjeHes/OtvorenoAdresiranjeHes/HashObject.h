#pragma once
#include<iostream>
class HashObject
{
protected:
	int x;
	int y;
	int z;
	double record;
public:
	HashObject();
	HashObject(int x, int y, int z, double rec);
	HashObject(const HashObject& o);
	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }
	int getRecord() { return record; }
	bool operator==(const HashObject& a);
	HashObject& operator=(const HashObject& o);
	bool isEqual(int x, int y, int z) { return this->x == x && this->y == y && this->z == z; }
	void print();
};

