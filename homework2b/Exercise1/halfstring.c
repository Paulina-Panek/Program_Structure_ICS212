/*****************************************************************
//  //  NAME:        Paulina Panek
//  //
//  //  HOMEWORK:    2b
//  //
//  //  CLASS:       ICS 212
//  //
//  //  INSTRUCTOR:  Ravi Narayan
//  //
//  //  DATE:        September 13th, 2018
//  //
//  //  FILE:        halfstring.c
//  //
//  //  DESCRIPTION:
//  //  Function that takes every other character from string_old   
//  //  and creates string_new from it.
//  //
//  *************************************************************/

#include <stdio.h>

/***************************************************************
//  Function name: halfstring()
//  //
//  //  DESCRIPTION:   Takes every other character of initial string 
//  //                 and creates a new string from them. Only works
//  //                 when a string properly terminated with a '\0'.
//  //
//  //  Parameters:    string_old(char []) initial string
//  //                 string_new(char []) string created from
//  //                 every other character of string_new
//  //
//  //  Return values: none (void)
//  //                
****************************************************************/

void halfstring(const char string_old[], char string_new[])
{
    int counter, i;

    counter = 0;

    for (i = 0; string_old[i] != '\0'; i++)
    {   
        if (i%2 == 0)
        { 
           string_new[counter] = string_old[i];
           counter++;
        } 
    }
}
