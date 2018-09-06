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
//  trcmp/   A simple program listing factors of an integer given
//  //   by user interface
//  //
//  //
//  *************************************************************/


#include <stdio.h>
#include <stdlib.h> /*atoi*/

int isDivisible(int, int);

/***************************************************************
//  Function name: isDivisible(number, PotentialFactor)
//  //
//  //  DESCRIPTION:   Checks if <number> is divisible by
//  //                 <PotentialFactor>
//  //
//  //  Parameters:    number : looking for factors of
//  //                 PotentialFactor : checked if is a factor              
//  //
//  //  Return values: 0 : <PotentialFactor> is NOT a factor
//  //                 1 : <PotentialFactor> is a factor
//  //
****************************************************************/

int main()
/***************************************************************
//  Function name: main()
//  //
//  //  DESCRIPTION:   Userinteface function, obtains an integer
//  //                 from user and generates an indexed table
//  //                 of factors
//  //
//  //  Parameters:    input[12] : input from the command line
//  //                 user_int : integer entered by the user
//  //                 obtained from input[]
//  //                             
//  //
//  //  Return values: always 0
//  //                 
//  //
****************************************************************/
{  
    int user_int, i, index, factor;
    char input[12];

    printf("This program calulates the factors of an integer provided by the user.\n");
    printf("Please enter an integer greater than 0:\n");

    fgets(input, 12, stdin);
    user_int = atoi(input);

    while (user_int <= 0)
    /*Ensures input not a character/string/0/negative integer*/
    {  
        printf("Incorrect input. Please enter a POSITIVE integer.\n");
        fgets(input, 12, stdin);
        user_int = atoi(input);
    }
       
    printf("You entered: %d\n\n", user_int);

    index = 1;

    printf("%10s", "Index");
    printf("%10s\n", "Factor");

    for (i = 1; i <= user_int; i++)
    {             
        factor = isDivisible(user_int, i);
                
        if (factor ==1)
        {
            printf("%10d%10d\n", index, i);
            index++;
        }
    }

    return(0);
}

int isDivisible(int number, int PotentialFactor)
{ 
    int result;
 
    if (number % PotentialFactor == 0)
        result = 1;
    else
        result = 0;                 

    return(result);
} 
