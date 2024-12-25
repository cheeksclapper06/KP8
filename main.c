#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "hexnum.h"
#include "circuit.h"
#include "complex.h"
#include "calculation.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
do
{
    printf("This program calculates set resistance oscillating circuit depending on the current frequency\n");

    char user_choice = 0;
    user_choice = select_circuit_type(user_choice);
    printf(RESET_COLOR "\nEnter the values of the circuit\n");
    printf(LIGHT_RED "WARNING " RESET_COLOR "all values have restriction [1e-3 - 1e3]\n\n");
    double L = 0.0, C = 0.0;
    L = validate_floating_value(RESET_COLOR "Enter the inductance " LIGHT_GREEN "L (mHn):\n" RESET_COLOR , condition_restriction);
    C = validate_floating_value(RESET_COLOR "Enter the capacitance " LIGHT_GREEN "C (mcF):\n" RESET_COLOR, condition_restriction);

    double R = 0.0;
    double R1 = 0.0, R2 = 0.0;

    switch(user_choice)
    {
        case RLC:
        case RCL:
        R = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R (Ohm):\n" RESET_COLOR, condition_restriction);
        break;

        case R2CLR1:
        case R1CR2L:
        R1 = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R1 (Ohm):\n" RESET_COLOR, condition_restriction);
        R2 = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R2 (Ohm):\n" RESET_COLOR, condition_restriction);
        break;

        default:
            break;
    }

    double fmin = 0.0, fmax = 0.0;
    do
    {
        fmin = validate_floating_value(RESET_COLOR "Enter the minimum frequency " LIGHT_GREEN "fmin (Hz):\n" RESET_COLOR, condition_restriction);
        fmax = validate_floating_value(RESET_COLOR "Enter the maximum frequency " LIGHT_GREEN "fmax (Hz):\n" RESET_COLOR, condition_restriction);
        if (fmin > fmax)
        {
            printf(LIGHT_RED "fmin should be lesser than fmax\n" RESET_COLOR);
        }
        fflush(stdin);
    }
    while (fmin > fmax);

    unsigned step = 0;
    do
    {
        step = validate_floating_value(RESET_COLOR "Enter the step "LIGHT_GREEN "df (Hz):\n" RESET_COLOR, condition_restriction);
        if ((double)step > fmax - fmin)
        {
            printf(LIGHT_RED "Step (df) should be lesser than the difference between minimum and maximum frequencies\n" RESET_COLOR);
        }
        fflush(stdin);
    }
    while ((double)step > fmax - fmin);

    double res_freq = 0.0;
    res_freq = 1.0 / (2.0 * M_PI * sqrt(L * C));
    printf("The resonance frequency is " LIGHT_GREEN "%.15lf Hz\n" RESET_COLOR, res_freq);

    double f = fmin;
    int i = 0;
    printf(LIGHT_YELLOW "|  F R E Q U E N C Y  | " LIGHT_GREEN "C O M P L E X  R E S I S T A N C E \n" RESET_COLOR);
    do
    {
        const double omega = calculate_angular_frequency(f);
        const complex z = calculate_complex_resistance(user_choice, R, R1, R2, L, C, omega);

        printf(LIGHT_YELLOW "|f%d  =   %.15lf\t   | " LIGHT_GREEN "z%d =  ", i + 1, f, i + 1);
        print_complex(z);

        i++;
        f += step;
    }
    while (f <= fmax);
    printf(RESET_COLOR "\nTo continue press " LIGHT_GREEN "ENTER, " RESET_COLOR "to exit press " LIGHT_RED "any other key\n" RESET_COLOR);
}
    while (getch() == ENTER);
    return 0;
}
