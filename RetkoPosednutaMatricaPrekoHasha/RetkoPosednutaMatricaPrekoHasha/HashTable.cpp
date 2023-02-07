#include "HashTable.h"
#include<math.h>
unsigned int HashTable::g(int i, int j)
{
    return h(f(i,j));
}

unsigned int HashTable::f(int i, int j)
{
    return i*k+j;
}

unsigned int HashTable::h(int k)
{
    unsigned int a = 2654435769;
    return (a*k) >> (32 - (int)log2(n));
}
