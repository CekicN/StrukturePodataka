#include "HashTable.h"

unsigned int HashTable::h(char* k)
{
    return g(f(k));
}

unsigned int HashTable::f(char* k)
{
    int b = 0;
    for (int i = 3; i < 9; i++)
    {
        b += k[i];
    }
    return b;

}

unsigned int HashTable::g(unsigned int k)
{
    unsigned int a = 2654435769;
    return (a*k) >> 26;
}
