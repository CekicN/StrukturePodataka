#include "sabirac.h"

int sabirac::toInt(char i)
{

	return i - '0';
}

char sabirac::toChar(int i)
{
	return i + '0';
}

sabirac::sabirac(int n1, int n2)
{
	a = new stek(n1);
	b = new stek(n2);
}

char* sabirac::saberi(char* br1, char* br2)
{	

	int i = 0;
	while (br1[i] != '\0')
	{
		a->push(toInt(br1[i]));
		i++;
	}
	i = 0;
	while (br2[i] != '\0')
	{
		b->push(toInt(br2[i]));
		i++;
	}
	stek* rez;
	rez = a->saberi(*b);
	char* suma = new char[rez->getBr()];
	i = 0;
	while (rez->getBr() != 0)
	{
		suma[i] = toChar(rez->pop());
		i++;
	}
	suma[i] = '\0';
	return suma;
}
