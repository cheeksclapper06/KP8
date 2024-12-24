#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "hexnum.h"
#include "circuit.h"
#include "complex.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
do
{
    printf("This program calculates set resistance oscillating circuit depending on the current frequency\n");

    char user_choice = 0;
    user_choice = select_circuit_type(user_choice);

    double L = 0.0, C = 0.0;
    L = validate_floating_value(RESET_COLOR "Enter the inductance " LIGHT_GREEN "L (mHn) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
    C = validate_floating_value(RESET_COLOR "Enter the capacitance " LIGHT_GREEN "C (mcF) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
    switch(user_choice)
    {
        case RLC:
        case RCL:
            double R = 0.0;
        R = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R (Ohm) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
        break;

        case R2CLR1:
        case R1CR2L:
        double R1 = 0.0, R2 = 0.0;
        R1 = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R1 (Ohm) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
        R2 = validate_floating_value(RESET_COLOR "Enter the resistance " LIGHT_GREEN "R2 (Ohm) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
        break;

        default:
            break;
    }

    double fmin = 0.0, fmax = 0.0;
    do
    {
        fmin = validate_floating_value(RESET_COLOR "Enter the minimum frequency " LIGHT_GREEN "fmin (Hz) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
        fmax = validate_floating_value(RESET_COLOR "Enter the maximum frequency " LIGHT_GREEN "fmax (Hz) " RESET_COLOR "[the value can't be negative]:\n", condition_negative);
        if (fmin > fmax)
        {
            printf(LIGHT_RED "fmin should be lesser than fmax\n" RESET_COLOR);
        }
        fflush(stdin);
    }
    while (fmin > fmax);

    double step = 0.0;
    do
    {
        step = validate_floating_value(RESET_COLOR "Enter the step "LIGHT_GREEN "df (Hz) " RESET_COLOR"(Hz) [the value can't be negative]:\n", condition_negative);
        if (step > fmax - fmin)
        {
            printf(LIGHT_RED "Step (df) should be lesser than the difference between minimum and maximum frequencies\n" RESET_COLOR);
        }
        fflush(stdin);
    }
    while (step > fmax - fmin);


    printf("\nTo continue press " LIGHT_GREEN "ENTER, " RESET_COLOR "to exit press " LIGHT_RED "any other key\n" RESET_COLOR);
}
    while (getch() == ENTER);
    return 0;
}