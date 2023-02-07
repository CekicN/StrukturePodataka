#include"RedAsArray.h"
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	RedAsArray<int> red(10);
	for (int i = 0; i < 5; i++)
	{
		red.enqueue(rand() % 10 + 1);
	}
	red.print();

	cout << red.dequeue() << endl;
	cout << red.dequeue() << endl;
	red.print();

	red.enqueue(25);
	red.print();
	
	return 0;
}