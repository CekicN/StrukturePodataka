#include "HashTable.h"

unsigned int HashTable::h(int x, int y, int z)
{
    return g(f(x,y,z));
}

unsigned int HashTable::f(int x, int y, int z)
{
    return x + M * (y + N * z);
}

unsigned int HashTable::g(int k)
{
    int a = 2654435770;
    return k%n;
}
