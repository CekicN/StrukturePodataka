#pragma once
#include<iostream>
using namespace std;
template<class T = int, class R = int>
class HashObject
{
protected:
	T key;
	R* record;

public:
	HashObject() { key = (T)0; record = nullptr; }
	HashObject(T k) { key = k; record = nullptr; }
	HashObject(T k, R* o) { key = k; record = o; }
	~HashObject() {}

	HashObject& operator=(HashObject const& obj)
	{
			key = obj.key;
			record = obj.record;
			
			return *this;
	}
	bool operator==(HashObject const& obj)
	{
		return record == obj.record;
	}
	void deleteRecord() {
		if (record)
		{
			delete record;
			record = nullptr;
		}
	}
	T getKey() { return key; }
	R* GetRecord() { return record; }
	bool isEqualKey(T k) { return key == k; }
	friend ostream& operator<<(ostream& izlaz, const HashObject& o)
	{
		if (o.record != nullptr)
		{
			izlaz << o.key << "|" << o.record;
		}
		
		return izlaz;
	}
};

