/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 22nd, 2018
//
//  FILE:        getaddress.c
//
//  DESCRIPTION:
//  Function that asks user for address and stores multiple lines   
//  of user input.
//
//  *************************************************************/


#include <stdio.h>


extern int debug;

void getaddress (char address[], int alreadyThere)
{
    char buffer[20];
    int i;

    printf("Please enter your address:\n");

    for (i=0;  buffer != '\0'; i++)
    {
    buffer[i] = fgetc(stdin);
    }
    
}
