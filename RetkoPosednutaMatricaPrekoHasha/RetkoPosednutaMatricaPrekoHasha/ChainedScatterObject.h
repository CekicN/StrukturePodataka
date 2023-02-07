#pragma once
#include"ScatterObject.h"
class ChainedScatterObject:public ScatterObject
{
public:
	int next;
public:
	ChainedScatterObject();
	ChainedScatterObject(int i, int j);
	ChainedScatterObject(int i, int j, int value);
	ChainedScatterObject(int i, int j, int value, int n);

	ChainedScatterObject& operator=(const ChainedScatterObject& cso);
	void print();
};

