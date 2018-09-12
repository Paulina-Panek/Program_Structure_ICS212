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
//  //  FILE:        practice.c
//  //
//  //  DESCRIPTION:
//  //   A simple program that asks user to provide their first and
//  //   last name, then generates a 6 character username in format
//  //   LastFirst. If such username is shorter than 6 characters it
//  //   adds 0s at the end. If it is longer, it'll cut it after the
//  //   6th character
//  //
//  *************************************************************/

#include <stdio.h>
#include <string.h>

/***************************************************************
//  Function name: main()
//  //
//  //  DESCRIPTION:   Generates 6 character username from user 
//  //                 first and last name
//  //
//  //  Parameters:    none
//  //                             
//  //
//  //  Return values: always 0
//  //                
****************************************************************/

int main ()
{
    char first[20], last[20],  username[6], ifshort[6];
    int length, howShort;

    printf("Please enter your first name:\n");
    scanf("%s", first);

    printf("Please enter your last name:\n");
    scanf("%s", last);

/* Generating username consisting of 6 characters */

    /* 1. STRCAT: Combine last with first */

    strcat(last, first);
    
    /* 2. STRLEN: Check lenght of appended string */

    length = strlen(last); 

    /* 3. STRCPY 4. STRNCAT If shorter than 6 characters, add 0s at the end.
       5. STRNCPY If longer than 6, take only the first 6 */

    if (length < 6)
    {
        strcpy(ifshort, "000000");
        howShort = 6 - length;
        strncat(last, ifshort, howShort);
    }

        strncpy(username, last, 6);


    printf("Your username is:\t%s\n", username);

 
return(0);
}
