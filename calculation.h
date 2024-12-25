#ifndef CALCULATION_H
#define CALCULATION_H

#include <stdio.h>
#include <math.h>
#include "hexnum.h"
#include "complex.h"

double calculate_angular_frequency(const double fmin)
{
    double f = 0.0, omega = 0.0;
    f = fmin;
    omega = 2.0 * M_PI * f;
    return omega;
}

complex RLC_calculation(const double R, const double L, const double C, const double omega)
{
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};
    numinator.real = L / C;
    numinator.imaginary = - (R / (omega * C));

    denominator.real = R;
    denominator.imaginary = omega * L - 1.0 /(omega * C);

    return complex_division(numinator, denominator);
}

complex RCL_calculation(const double R, const double L, const double C, const double omega)
{
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = L / C;
    numinator.imaginary = R / (omega * C);

    denominator.real = R;
    denominator.imaginary = omega * L - 1.0 / (omega * C);

    return complex_division(numinator, denominator);
}

complex R2CLR1_calculation(const double R1, const double R2, const double L, const double C, const double omega)
{
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = R1 * R2;
    numinator.imaginary = R1 * (omega * L - 1.0 /(omega * C));

    denominator.real = R1 + R2;
    denominator.imaginary = omega * L - 1.0 / (omega * C);

    return complex_division(numinator, denominator);
}

complex R1CR2L_calculation(const double R1, const double R2, const double L, const double C, const double omega)
{
    complex numinator = {0.0, 0.0}, denominator = {0.0, 0.0};

    numinator.real = R1 * R2 + L / C;
    numinator.imaginary = omega * L * R1 - R2 / (omega * C);

    denominator.real = R1 + R2;
    denominator.imaginary = omega * L - 1.0 / (omega * C);

    return complex_division(numinator, denominator);
}

complex calculate_complex_resistance(const int circuit_type, const double R, const double R1, const double R2, const double L, const double C, const double omega)
{
    switch (circuit_type)
    {
        case RLC:
            return RLC_calculation(R, L, C, omega);

        case RCL:
            return RCL_calculation(R, L, C, omega);

        case R2CLR1:
            return R2CLR1_calculation(R1, R2, L, C, omega);

        case R1CR2L:
            return R1CR2L_calculation(R1, R2, L, C, omega);

        default:
            break;
    }
}
#endif //CALCULATION_H
