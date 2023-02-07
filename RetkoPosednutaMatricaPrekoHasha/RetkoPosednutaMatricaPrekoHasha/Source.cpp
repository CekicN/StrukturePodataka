#include"ChainedScatterTable.h"
#include<iostream>
using namespace std;
int main()
{
	ChainedScatterTable matrica1(5, 4);
	ChainedScatterTable matrica2(4, 5);
	int** a;
	a = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = new int[4];
	}
	int** b;
	b = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		b[i] = new int[5];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl << endl;
	cout << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
		}
	}
	matrica1.insert(a);
	matrica2.insert(b);
	
	matrica1.print();
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	matrica2.print();
	return 0;
}