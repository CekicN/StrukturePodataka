#include "ScatterObject.h"

ScatterObject::ScatterObject() : HashObject()
{
	status = 0;
}

ScatterObject::ScatterObject(const char* key, const char* ime, int br) : HashObject(key,ime,br)
{
	status = 0;
}

ScatterObject::ScatterObject(const ScatterObject& o) : HashObject(o)
{
	status = o.status;
}

ScatterObject& ScatterObject::operator=(const ScatterObject& o)
{
	if (this != &o)
	{
		(HashObject&)(*this) = o;
		status = o.status;
	}
	return *this;
}
