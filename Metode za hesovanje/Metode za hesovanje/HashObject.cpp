#include "HashObject.h"

HashObject::HashObject()
{
	key = value = -1;
}


HashObject::HashObject(unsigned int key)
{
	this->key = key;
	value = -1;
}

HashObject::HashObject(unsigned int key, unsigned int value)
{
	this->key = key;
	this->value = value;
}

HashObject::HashObject(const HashObject& o)
{
	if (this != &o)
	{
		key = o.key;
		value = o.value;
	}
}

HashObject& HashObject::operator=(const HashObject& o)
{
	if (this != &o)
	{
		key = o.key;
		value = o.value;
	}
	return *this;
}

bool HashObject::operator==(const HashObject& o)
{

	return key == o.key && value == o.value;
}

void HashObject::print()
{
	if (key != -1)
	{
		std::cout << key;
	}
	if (value != -1)
	{
		std::cout << " | " << value;
	}
}
