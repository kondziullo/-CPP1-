#include "GSeries.h"
#include <iostream>
#include <cstdio>
#include <vector>

std::vector<ciag> created;


typedef int rozmiarCiagu;
typedef float* ciag;

ciag InicjalizujCiagGeometryczny(int size, float q)
{
    ciag geometryczny = new float[size];
    geometryczny[0] = 1;

    for(int i = 1; i < size; i++)
    {
        geometryczny[i] = geometryczny[i-1] * q;
    }
    
    created.push_back(geometryczny);
    return geometryczny;
}

void Wypisz(ciag print, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << print[i] << " ";
    }
}

void UsunCiagi()
{
    for(int i = 0; i < created.size(); i++)
    {
        delete[] created[i];
    }
    created.clear();
}
