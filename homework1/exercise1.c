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
#include <stdlib.h>

int getInt();
int isDivisible(int, int);

int main()
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
                
        if (factor ==1)
        {
            printf("%10d%10d\n", index, i);
            index++;
        }
    }

    return(0);
}

int getInt()
/***************************************************************
//  Function name: getInt()
//  //
//  //  DESCRIPTION:   Userinterface function that requests user
//  //                 to provide input and checks if it is a 
//  //                 positive integer
//  //
//  //  Parameters:    none
//  //                               
//  //  Return values: user_int : positive integer               
//  //
****************************************************************/
 
{
    char input[12];
    int user_int;

    printf("Please enter an integer greater than 0:\n");
    fgets(input, 12, stdin);

    /* Loops below ensure correct error message is displayed even
    // if incorrect input is provided multiple times in a row */

    while (input[0] == '0')
    {
        printf("You entered 0. Please enter a POSITIVE integer.\n");
        fgets(input, 12, stdin);
    }

    user_int = atoi(input);

    /* atoi returns 0 if characters were entered
    // Previous loop ensured that user didn't enter 0
    // Thus, if user_int = 0 characters were entered
    // If integer entered, atoi returns integer (+ or -) */

    while (user_int <= 0)
    { 
        if  (user_int == 0)
        {
             printf("You entered character(s). Please enter an integer.\n");
        }
  
        else if (user_int <= 0)
        {  
            printf("Please enter a POSITIVE integer to check its factors:\n");   
        }
     
        fgets(input, 12, stdin);
   
    /* Once user enters new input, below loop will first evaluate if it was 0
    // Then, again use atoi and go through the loop to ensure new input not a 
    // character */
 
        while (input[0] == '0')
        {
            printf("You entered 0. Please enter a POSITIVE integer.\n");
            fgets(input, 12, stdin);
        }

        user_int = atoi(input);
    }

return(user_int);  
}


int isDivisible(int number, int PotentialFactor)
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

{ 
    int result;
 
    if (number % PotentialFactor == 0)
        result = 1;
    else
        result = 0;                 

    return(result);
} 
