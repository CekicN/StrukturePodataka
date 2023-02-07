#include "ChainedScatterObject.h"

ChainedScatterObject::ChainedScatterObject():ScatterObject()
{
	next = -1;
}

ChainedScatterObject::ChainedScatterObject(int i, int j):ScatterObject(i,j)
{
	next = -1;
}

ChainedScatterObject::ChainedScatterObject(int i, int j, int value):ScatterObject(i,j,value)
{
	next = -1;
}

ChainedScatterObject::ChainedScatterObject(int i, int j, int value, int n):ScatterObject(i,j,value)
{
	next = n;
}

ChainedScatterObject& ChainedScatterObject::operator=(const ChainedScatterObject& cso)
{
	if (this != &cso)
	{
		(ScatterObject&)(*this) = cso;
		next = cso.next;
	}
	return *this;
}

void ChainedScatterObject::print()
{
	if (i != -1)
	{
		std::cout << "(" << i << ",";
	}
	if (j != -1)
	{
		std::cout << j << ")" << " | " << value;
	}
	std::cout << " | " << next << std::endl;
}
