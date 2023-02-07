//#include"StackAsArray.h"
#include"StackAsLinkedList.h"
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	StackAsLinkedList<int> stek;

	for (int i = 0; i < 5; i++)
	{
		stek.push((rand()%10) + 1);
	}
	stek.Stampaj();

	cout << stek.pop() << endl;

	stek.Stampaj();
	return 0;
}