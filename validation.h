#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "color.h"

bool condition_restriction(const double value)
{
    return value < MIN || value > MAX;
}

double validate_floating_value(const char *message, bool (*condition)(double))
{
    bool InvalidInput;
    double value = 0.0;
    do
    {
        printf("%s", message);
        if (scanf("%lf", &value) != 1 || condition(value))
        {
            printf(LIGHT_RED "Please enter a valid floating value\n" RESET_COLOR);
            fflush(stdin);
            InvalidInput = true;
        }
        else
        {
            fflush(stdin);
            InvalidInput = false;
        }
    }
    while (InvalidInput);
    return value;
}
char validate_input_getch(const unsigned start_option, const unsigned end_option)
{
    char input = 0;
    do
    {
        input = getch();
        if (input < start_option || input > end_option)
        {
            printf(LIGHT_RED "Please enter a number in given range\n" RESET_COLOR);
        }
        else
        {
            return input;
        }
    }
    while (input < start_option || input > end_option);
}

#endif
