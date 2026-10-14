#include "GOperations.h"
#include <iostream>
#include <cstdio>

typedef int rozmiarCiagu;
typedef float* ciag;
typedef float (*operacja)(ciag, int);

float Suma(ciag first, int size)
{
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        count = count + first[i];
    }

    return count;
}

float Iloczyn(ciag second, int size)
{
    int count = 1;
    
    for(int i = 0; i < size; i++)
    {
        count = count * second[i];
    }

    return count; 
}

float Max(ciag third, int size)
{
    int maximum = third[0];
    int minimum = third[0];

    for(int i = 0; i < size; i++)
    {
        if(third[i] > maximum)
        {
            maximum = third[i];
        }
        if(third[i] < minimum)
        {
            minimum = third[i];
        }
    }

    std::cout << "minimum: " << minimum << std::endl;

    return maximum;
}

float Wykonaj(operacja function, ciag fourth, int size)
{
    return function(fourth, size);
}