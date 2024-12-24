#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct
{
    double real;
    double imaginary;
} complex;

double complex_division(const complex *first, const complex *second)
{
    return (first->real * second->real + first->imaginary * second->imaginary) / (second->real * second->real + second->imaginary * second->imaginary);
}

void print_complex(const complex *complex_number)
{
    printf("%e + %ei", complex_number->real, complex_number->imaginary);
}
#endif //COMPLEX_H
