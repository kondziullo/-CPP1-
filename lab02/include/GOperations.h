// w tym pliku definiujemy działania na ciągu geometrycznym

#include <cstdio>

typedef int rozmiarCiagu;
typedef float* ciag;
typedef float (*operacja)(ciag, int);

float Suma(ciag first, int size);
float Iloczyn(ciag second, int size);
float Max(ciag third, int size);
float Wykonaj(operacja function, ciag fourth, int size);