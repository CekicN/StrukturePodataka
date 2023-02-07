#include "HashObject.h"

HashObject::HashObject()
{
	key = nullptr;
	ime = nullptr;
}

HashObject::HashObject(const char* key, const char* ime,int br)
{
	this->key = strcpy(new char[strlen(key) + 1], key);
	this->ime = strcpy(new char[strlen(ime) + 1], ime);
	brBodova = br;
}


HashObject::HashObject(const HashObject& o)
{
	this->key = strcpy(new char[strlen(o.key) + 1], o.key);
	this->ime = strcpy(new char[strlen(o.ime) + 1], o.ime);
	brBodova = o.brBodova;
}

HashObject::~HashObject()
{
	if (key != nullptr)
	{
		delete[] key;
	}
	if (ime != nullptr)
	{
		delete[] ime;
	}
	
}

HashObject& HashObject::operator=(const HashObject& o)
{
	if (this != &o)
	{
		if (key)
		{
			delete key;
		}
		if (o.key != nullptr)
		{
			key = strcpy(new char[strlen(o.key) + 1], o.key);
		}
		
		
		if (ime)
		{
			delete ime;
		}
		if (o.ime)
		{
			ime = strcpy(new char[strlen(o.ime) + 1], o.ime);
		}
		brBodova = o.brBodova;
	}
	return *this;
}

bool HashObject::operator==(const HashObject& o)
{

	return strcmp(key,o.key) == 0 && strcmp(ime, o.ime) == 0 && brBodova == o.brBodova;
}

bool HashObject::isEqual(char* key)
{
	if (this->key != nullptr)
	{
		return strcmp(this->key, key) == 0;
	}
	return false;
}

void HashObject::deleteValue()
{
	if (ime)
	{
		delete[] ime;
		ime = nullptr;
	}
	brBodova = -1;
}

void HashObject::print()
{
	if (key)
	{
		std::cout << key;
	}
	if (ime)
	{
		std::cout << " | " << ime << " | " << brBodova;
	}
	
	std::cout << std::endl;
}
