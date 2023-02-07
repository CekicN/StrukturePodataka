#include"Niz.h"
#include<iostream>

using namespace std;

int main()
{
	Niz<int> a(5);

	a.Set(5, 1);
	cout << a[1];
	return 0;
}