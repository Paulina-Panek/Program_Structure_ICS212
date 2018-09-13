/***************************************************************
//  //  NAME:        Paulina Panek
//  //
//  //  HOMEWORK:    2b
//  //
//  //  CLASS:       ICS 212
//  //
//  //  INSTRUCTOR:  Ravi Narayan
//  //
//  //  DATE:        September 13, 2018
//  //
//  //  FILE:        driver.c
//  //
//  //  DESCRIPTION:
//  //   This file contains the driver for halfstring function. Uses
//  //   user-input to test the functon.
//  //
//  ****************************************************************/

#include "halfstring.h"
#include <stdio.h>

/***************************************************************
//  Function name: main()
//  //
//  //  DESCRIPTION:   Driver to test function halfstring 
//  //                 
//  //
//  //  Parameters:    none
//  //                             
//  //
//  //  Return values: always 0
//  //                
****************************************************************/

int main()
{
    int  i, j, size_new;
    char string_old[200], string_new[101];

    printf("Enter the string you want to process:\n");
    fgets(string_old, 200, stdin);

    i = 0;

    while (string_old[i] != '\0')
    {
        i++;
    } 

    size_new = (i/2);

    string_new[size_new] ='\0';
    
    for (i = 0; i < size_new; i++)
    {
        string_new[i] = 'a';

    /* string_new here is just an array place holder */

    } 
    
    halfstring(string_old, string_new);

    printf("Old string:\t%s\n", string_old);
    printf("New string:\t%s\n", string_new);

return(0);
}
