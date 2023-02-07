#include"sabirac.h"

int main()
{
	char a[] = "234524876023227";
	char b[] =      "1243808276";
	sabirac z(16, 11);

	char* br = z.saberi(a, b);
	cout << br;
	return 0;
}