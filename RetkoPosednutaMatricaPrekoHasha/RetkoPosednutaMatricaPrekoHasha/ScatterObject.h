#pragma once
#include"HashObject.h"
class ScatterObject:public HashObject
{
public:
	int status;//0-slobodno 1-zauzeto 2-obrisano
public:
	ScatterObject();
	ScatterObject(int i, int j);
	ScatterObject(int i, int j, int value);
	ScatterObject(const ScatterObject& so);

	ScatterObject& operator=(const ScatterObject& so);
};

