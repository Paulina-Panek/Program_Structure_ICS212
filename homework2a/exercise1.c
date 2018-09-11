/*****************************************************************
//  //  NAME:        Paulina Panek
//  //
//  //  HOMEWORK:    1
//  //
//  //  CLASS:       ICS 212
//  //
//  //  INSTRUCTOR:  Ravi Narayan
//  //
//  //  DATE:        September 6th, 2018
//  //
//  //  FILE:        exercise1.c
//  //
//  //  DESCRIPTION:
//  //   A simple program listing factors of an integer given
//  //   by user interface
//  //
//  //
//  *************************************************************/

#include <stdio.h>
#include "exercise1.h"

/***************************************************************
//  Function name: main()
//  //
//  //  DESCRIPTION:   Generates an indexed table
//  //                 of factors of a positive integer
//  //
//  //  Parameters:    none
//  //                             
//  //
//  //  Return values: always 0
//  //                
****************************************************************/

int main()
{  
    int user_int, i, index, factor;

    printf("This program calulates the factors of an integer provided by the user.\n");

    user_int = getInt();
    printf("You entered: %d\n\n", user_int);

    index = 1;

    printf("%10s%10s\n", "Index", "Factor");

    for (i = 1; i <= user_int; i++)
    {             
        factor = isDivisible(user_int, i);
                
        if (factor == 1)
        {
            printf("%10d%10d\n", index, i);
            index++;
        }
    }

    return(0);
}


