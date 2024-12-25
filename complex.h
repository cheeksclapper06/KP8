#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>

typedef struct
{
    double real;
    double imaginary;
} complex;

complex complex_division(complex first, complex second)
{
    complex result = {0.0, 0.0};
    result.real = (first.real * second.real + first.imaginary * second.imaginary) / (second.real * second.real + second.imaginary * second.imaginary);
    result.imaginary = (second.real * first.imaginary - first.real * second.imaginary) / (second.real * second.real + second.imaginary * second.imaginary);
    return result;
}

void print_complex(complex complex_number)
{
    printf("%e + i * %lf\n", complex_number.real, complex_number.imaginary);
}
#endif //COMPLEX_H
