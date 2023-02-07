#include "ChainedScatterObject.h"

ChainedScatterObject::ChainedScatterObject():ScatterObject()
{
	next = -1;
}


ChainedScatterObject::ChainedScatterObject(const char* key, const char* ime, int br):ScatterObject(key, ime, br)
{
	next = -1;
}

ChainedScatterObject::ChainedScatterObject(const char* key, const char* ime, int br, int n) : ScatterObject(key, ime,br)
{
	this->next = n;
}

ChainedScatterObject::ChainedScatterObject(const ChainedScatterObject& o): ScatterObject(o)
{
	next = o.next;
}

ChainedScatterObject& ChainedScatterObject::operator=(const ChainedScatterObject& o)
{
	if (this != &o)
	{
		(ScatterObject&)(*this) = o;
		next = o.next;
	}
	return *this;
}

void ChainedScatterObject::print()
{
	if (getKey() != nullptr)
	{
		std::cout << key;
	}
	if (ime != nullptr)
	{
		std::cout << " | " << ime << " | " << brBodova;
	}

	std::cout << " | " << next << std::endl;
}
