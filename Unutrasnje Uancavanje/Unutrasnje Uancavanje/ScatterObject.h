#pragma once
#include"HashObject.h"
class ScatterObject : public HashObject
{
public:
	int status; // 0-slobodan, 1- obrisan, 2-zauzet
public:
	ScatterObject();
	ScatterObject(const char* key, const char* ime,int br);
	ScatterObject(const ScatterObject& o);

	ScatterObject& operator=(const ScatterObject& o);

};

