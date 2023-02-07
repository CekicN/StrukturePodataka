#pragma once
#include"LinkedNode.h"
#include"LinkedEdge.h"
class Graph
{
	LinkedNode* start;
	int br;
	void setStatusForAllNodes(int status);
public:
	Graph();
	~Graph();
	LinkedNode* findNode(int& data);
	LinkedEdge* findEdge(int& dataSrc, int& dataDest);
	void insertNode(int& data);
	bool insertEdge(int& dataSrc, int& dest,const double& w = 0);
	void print();
	long breadthFirstTraversal(int& data);

	//BLANKETI
	//Jun2021
	int findPath(int a, int b, int& cvorovi);
	int findPath(int a, int b, int c, int duzina);
	//Oktobar2021
	bool CanReachMoreWithUndirected(int a);
	//Oktobar2020
	int fly(int a);
};

