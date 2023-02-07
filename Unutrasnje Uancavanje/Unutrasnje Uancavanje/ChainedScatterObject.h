#pragma once
#include"ScatterObject.h"
class ChainedScatterObject : public ScatterObject
{
public:
	int next;
public:
	ChainedScatterObject();
	ChainedScatterObject(const char* key, const char* ime, int br);
	ChainedScatterObject(const char* key, const char* ime, int br, int n);
	ChainedScatterObject(const ChainedScatterObject& o);

	ChainedScatterObject& operator=(const ChainedScatterObject& o);
	void print();
};

