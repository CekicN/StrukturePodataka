#include"MultiDimensional.h"
#include<iostream>
using namespace std;
int main()
{
	long args[] = { 5, 4, 3, 5, 8 };
	long ind[] = { 3, 2, 1, 3, 6 };
	MultiDimensional<int> m(args, 5);
	m.setAt(10, ind, 5);
	//cout << m.getAt(ind, 5)<<endl;
	m.randUnos();

	cout << m.obilazak(0, 2500);

}