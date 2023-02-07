#include "HashTable.h"
#include<iostream>
#include<math.h>
using namespace std;
unsigned int HashTable::h(char* key)
{
    return g(f(key));
}

unsigned int HashTable::f(char* key)
{
    int b = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        b += key[i];
    }
    return b;
}


unsigned int HashTable::g(int e)
{
    return e%n;
}

unsigned int HashTable::gSquare(unsigned int e)
{
    int x = (int)(log2(n));
    unsigned int c = ((e * e) >> (32 - x));
    return c;
}

unsigned int HashTable::gFibonacci(unsigned int e)
{
    
    long a = pow(2,32) * 0.618033887;
    return (e * a) >> (32 - (int)log2(n));
}
