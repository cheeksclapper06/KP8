#ifndef CALCULATION_H
#define CALCULATION_H

#include <stdio.h>
#include <math.h>
#include "complex.h"

double calculate_angular_frequency(const double fmin, const double fmax)
{
    double f = 0.0, omega = 0.0;
    f = fmin;
    omega = 2.0 * M_PI * f;
    return omega;
}

double RLC_calculation(const double R, const double L, const double C, const double omega)
{
    const complex z = {0.0, 0.0};
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = L / C;
    numinator.imaginary = - (R / (omega * C));

    denominator.real = R;
    denominator.imaginary = omega * L - 1.0 / C;

    return complex_division(&z, &z);
}

double RCL_calculation(const double R, const double L, const double C, const double omega)
{
    const complex z = {0.0, 0.0};
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = L / C;
    numinator.imaginary = R / (omega * C);

    denominator.real = R;
    denominator.imaginary = omega * L + 1.0/C;

    return complex_division(&z, &z);
}

double R2CLR1_calculation(const double R1, const double R2, const double L, const double C, const double omega)
{
    const complex z = {0.0, 0.0};
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = R1 * R2 + L / C;
    numinator.imaginary = R1 * (omega * L - 1.0 / C);

    denominator.real = R1 + R2;
    denominator.imaginary = numinator.imaginary;

    return complex_division(&z, &z);
}
#endif //CALCULATION_H
