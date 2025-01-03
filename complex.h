#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct
{
    double real;
    double imaginary;
} complex;

complex complex_division(const complex first, const complex second)
{
    complex result = {0.0, 0.0};
    result.real = (first.real * second.real + first.imaginary * second.imaginary) / (second.real * second.real + second.imaginary * second.imaginary);
    result.imaginary = (second.real * first.imaginary - first.real * second.imaginary) / (second.real * second.real + second.imaginary * second.imaginary);
    return result;
}

void print_complex(const complex complex_number)
{
    printf("%e + i * %e\n", complex_number.real, complex_number.imaginary);
}
#endif //COMPLEX_H
