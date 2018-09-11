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

#include <stdio.h> 
#include <stdlib.h>

int getInt()

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
    // Then, again use atoi and go through the big loop to ensure new input 
    // not a character */
 
        while (input[0] == '0')
        {
            printf("You entered 0. Please enter a POSITIVE integer.\n");
            fgets(input, 12, stdin);
        }

        user_int = atoi(input);
    }

return(user_int);  
}
