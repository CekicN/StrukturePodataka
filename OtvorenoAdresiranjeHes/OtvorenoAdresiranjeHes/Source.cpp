#include"OpenScatterTable.h"

int main()
{
	OpenScatterTable tablica(3,3,3);
	double a[3][3][3] = {
		1,3,2,
		4,0,6,
		0,0,9,
		0,3,0,
		4,0,0,
		0,8,9,
		1,0,2,
		4,0,0,
		0,8,0
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				tablica.insert(*new ScatterObject(i, j, k, a[i][j][k]));
			}
		}
	}
	tablica.print();
	return 0;
}