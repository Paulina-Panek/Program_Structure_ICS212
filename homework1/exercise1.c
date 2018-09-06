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
//  //  FILE:        homework1.c
//  //
//  //  DESCRIPTION:
//  //   A simple program listing factors of an integer given
//  //   by user interface
//  //
//  //
//  *************************************************************/

#include <stdio.h>
#include <stdlib.h> /*atoi*/

int isDivisible(int, int);

/***************************************************************
//  Function name: isDivisible(user_int, i)
//  //
//  //  DESCRIPTION:   Checks if the user integer (user_int) is divisible by
//  //                 integers from 1 to user_int
//  //
//  //  Parameters:    user_int : integer entered by the user
//  //                               
//  //
//  //  Return values: a table with indexed factors of user_int
//  //                 
//  //
****************************************************************/

int main()
{
    
    int user_int, i, index;
    char input[12];

    printf("This program calulates the factors of an integer provided by the user.\n");
    printf("Please enter an integer greater than 0:\n");
    

    fgets(input, 12, stdin);
    
    user_int = atoi(input);

    while  (user_int == 0)
    {
        printf("You entered character(s). Please enter an integer.\n");
        fgets(input, 12, stdin);
        user_int = atoi(input);
    }

    while (user_int <= 0)
    {
        printf("You entered: %d\n", user_int);
        printf("Please enter a POSITIVE integer to check its factors:\n");
        fgets(input, 12, stdin);
        user_int = atoi(input);         
    }
    
       
    printf("You entered: %d\n\n", user_int);

    printf("%10s", "Index");
    printf("%10s\n", "Factor");

    index = 1;

    for (i = 1; i <= user_int; i++)
    {             
                    
        int isDivisible(int user_int, int i);
        {
            if (user_int%i == 0)
                {
                    printf("%10d%10d\n", index, i);
                    index++;
                }                 
        } 
    }

    return(0);
}
