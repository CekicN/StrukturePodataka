#include "ScatterObject.h"

ScatterObject::ScatterObject():HashObject()
{
	status = 0;
}

ScatterObject::ScatterObject(int i, int j):HashObject(i,j)
{
	status = 0;
}

ScatterObject::ScatterObject(int i, int j, int value):HashObject(i,j,value)
{
	status = 0;
}

ScatterObject::ScatterObject(const ScatterObject& so):HashObject(so)
{
	status = so.status;
}

ScatterObject& ScatterObject::operator=(const ScatterObject& so)
{
	if (this != &so)
	{
		(HashObject&)(*this) = so;
		this->status = so.status;
	}
	return *this;
}
