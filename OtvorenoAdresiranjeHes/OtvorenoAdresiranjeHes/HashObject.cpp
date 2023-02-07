#include "HashObject.h"

HashObject::HashObject()
{
	x = -1;
	y = -1;
	z = -1;
	record = -1;
}

HashObject::HashObject(int x, int y, int z, double rec)
{
	this->x = x;
	this->y = y;
	this->z = z;
	record = rec;
}

HashObject::HashObject(const HashObject& o)
{
	x = o.x;
	y = o.y;
	z = o.z;
	record = o.record;
}

bool HashObject::operator==(const HashObject& a)
{
	return x == a.x && y == a.y && z == a.z && record == a.record;
}

HashObject& HashObject::operator=(const HashObject& o)
{
	if (this != &o)
	{
		x = o.x;
		y = o.y;
		z = o.z;
		record = o.record;
	}
	return *this;
}

void HashObject::print()
{
	if (x != -1)
	{
		std::cout << x;
	}
	if (y != -1)
	{
		std::cout<<" | " << y;
	}
	if (z != -1)
	{
		std::cout<<" | " << z;
	}
	if (record != -1)
	{
		std::cout << " | " << record;
	}

}
