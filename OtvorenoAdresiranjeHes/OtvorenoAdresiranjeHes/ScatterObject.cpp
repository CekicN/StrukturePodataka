#include "ScatterObject.h"

ScatterObject::ScatterObject():HashObject()
{
	status = 0;
}

ScatterObject::ScatterObject(int x, int y, int z, double rec):HashObject(x,y,z,rec)
{
	status = 0;
}

ScatterObject::ScatterObject(const ScatterObject& o):HashObject(o)
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
