#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T info;
	Node<T>* next;

public:
	Node();
	Node(T info);
	Node(T info, Node<T>* n);
	~Node() {}
	friend ostream& operator<<(ostream& izlaz, const Node<T>* n)
	{
		izlaz << n->info;
		return izlaz;
	}
};

template<class T>
inline Node<T>::Node()
{
	info = 0;
	next = nullptr;
}
template<class T>
inline Node<T>::Node(T info, Node<T>* n)
{
	this->info = info;
	next = n;
}
template<class T>
inline Node<T>::Node(T info)
{
	this->info = info;
	next = nullptr;
}
