#include "HashObject.h"

HashObject::HashObject()
{
	i = j = -1;
	value = 0;
}

HashObject::HashObject(int i, int j)
{
	this->i = i;
	this->j = j;
	value = 0;
}

HashObject::HashObject(int i, int j, int value)
{
	this->i = i;
	this->j = j;
	this->value = value;
}

bool HashObject::operator==(const HashObject& o)
{
    return i == o.i && j == o.j && value == o.value;
}

HashObject& HashObject::operator=(const HashObject& o)
{
	if (this != &o)
	{
		i = o.i;
		j = o.j;
		value = o.value;
	}
	return *this;
}

void HashObject::print()
{
	std::cout << "(" << i << "," << j << ")" << " | " << value<<std::endl;
}
