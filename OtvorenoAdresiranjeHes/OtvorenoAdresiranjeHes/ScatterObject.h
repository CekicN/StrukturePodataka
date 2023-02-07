#pragma once
#include"HashObject.h"
class ScatterObject:public HashObject
{
public:
	int status;
	ScatterObject();
	ScatterObject(int x, int y, int z, double rec);
	ScatterObject(const ScatterObject& o);

	ScatterObject& operator=(const ScatterObject& o);
};

