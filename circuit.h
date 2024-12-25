#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stdio.h>
#include <conio.h>
#include "color.h"
#include "hexnum.h"
#include "validation.h"

void RLC_circuit()
{
    printf("RLC circuit \n"
                   "●─┬──▆▆▆──────◠◠◠◠─┬─●\n"
                   "  │   R         L  │\n"
                   "  │                │\n"
                   "  │         C      │\n"
                   "  └────────││──────┘\n");
}

void RCL_circuit()
{
    printf("RCL circuit\n "
                  "●─┬─▆▆▆──────││───┬─●\n"
                  "   │  R        C   │\n"
                  "   │               │\n"
                  "   │      L        │\n"
                  "   └────◠◠◠◠───────┘\n");
}

void R2CLR1_circuit()
{
    printf("R2CLR1 circuit:\n "
                   "●─┬─▆▆▆──────││─────┓\n"
                   "   │ R2        C     │\n"
                   "   │                 │\n"
                   "   █ R1     L        │\n"
                   " ●─┴──────◠◠◠◠───────┘\n");
}

void R1CR2L_circuit()
{
    printf("R1CR2L circuit \n"
                   "●─┬────────▆▆▆───────┓\n"
                   "  █ R1     R2        │\n"
                   "  ┴                  │\n"
                   "  ┬ C       L        │\n"
                   "●─┴───────◠◠◠◠───────┚\n");
}

char select_circuit_type(char circuit_choice)
{
    printf(LIGHT_BLUE "Select the circuit type:\n" RESET_COLOR);
    for (int i = 1; i <= 4; i++)
    {
        printf(" %d - ", i);
        switch (i)
        {
            case 1:
              RLC_circuit();
              break;

            case 2:
              RCL_circuit();
              break;

            case 3:
              R2CLR1_circuit();
              break;

            case 4:
              R1CR2L_circuit();
              break;

            default:
                break;
        }
        printf("\n");
    }

    circuit_choice = validate_input_getch(RLC, R1CR2L);
    switch (circuit_choice)
    {
        case RLC:
            printf(LIGHT_GREEN "Your choice is:\n");
            RLC_circuit();
            break;

        case RCL:
            printf(LIGHT_GREEN "Your choice is:\n");
            RCL_circuit();
            break;

        case R2CLR1:
            printf(LIGHT_GREEN "Your choice is:\n");
            R2CLR1_circuit();
            break;

        case R1CR2L:
            printf(LIGHT_GREEN "Your choice is:\n");
            R1CR2L_circuit();
            break;

        default:
            printf(LIGHT_RED "Invalid choice. Please choose a valid option\n" RESET_COLOR);
            break;
    }
    return circuit_choice;
}


#endif //CIRCUIT_H