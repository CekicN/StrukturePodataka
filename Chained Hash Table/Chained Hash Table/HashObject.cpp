#include "HashObject.h"

HashObject::HashObject()
{
	key = record = nullptr;
}

HashObject::HashObject(char* key)
{
	this->key = strcpy(new char[strlen(key) + 1], key);
}

HashObject::HashObject(char* key, char* record)
{
	this->key = strcpy(new char[strlen(key) + 1], key);
	this->record = strcpy(new char[strlen(record) + 1], record);
}

HashObject::HashObject(const HashObject& o)
{
	this->key = strcpy(new char[strlen(o.key) + 1], o.key);
	this->record = strcpy(new char[strlen(o.record) + 1], o.record);

}

HashObject::~HashObject()
{
	if (key)
	{
		delete[] key;
	}
	if (record)
	{
		delete[] record;
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
		this->key = strcpy(new char[strlen(o.key) + 1], o.key);
		if (record)
		{
			delete record;
		}
		this->record = strcpy(new char[strlen(o.record) + 1], o.record);
	}
	return *this;
}

bool HashObject::operator==(const HashObject& o)
{

	return ((strcmp(key, o.key) == 0) && (strcmp(record, o.record) == 0));
}

void HashObject::deleteRecord()
{
	if (record)
	{
		delete record;
		record = nullptr;
	}
}

void HashObject::print()
{
	if (key != nullptr)
	{
		cout << key;
	}
	if (record != nullptr)
	{
		cout << " | " << record;
	}
	
}
