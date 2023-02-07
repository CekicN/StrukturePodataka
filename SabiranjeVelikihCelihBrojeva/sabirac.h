#pragma once
#include"stek.h"
class sabirac
{
	stek* a;
	stek* b;

	int toInt(char i);
	char toChar(int i);
public:
	sabirac(int n1, int n2);

	char* saberi(char* br1, char* br2);
};

