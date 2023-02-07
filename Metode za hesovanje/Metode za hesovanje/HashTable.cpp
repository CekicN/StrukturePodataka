#include "HashTable.h"
#include<iostream>
#include<math.h>
#include<bitset>
unsigned int HashTable::h(unsigned int e)
{
    return gFibonacci(e);
}

//unsigned int HashTable::f(unsigned int e)
//{
//    return e;
//}

unsigned int HashTable::g(unsigned int e)
{
    return e % n;
}
unsigned int HashTable::gSquare(unsigned int e)
{
    int x = (32 - (int)log2(n));
    x = (e * e) >> x;
    /*std::bitset<64> b(e * e);
    std::cout << b<<std::endl;
    std::bitset<32> a(x);
    std::cout << a;*/
    return x;
}

unsigned int HashTable::gFibonacci(unsigned int e)
{
    unsigned int a = pow(2,32) * 0.61803399;
    return (a*e) >> (32 - (int)(log2(n)));
}

