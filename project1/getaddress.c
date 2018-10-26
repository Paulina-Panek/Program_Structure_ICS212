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
//  Function that stores multiple lines   
//  of user input.
//
//  Parameters:  address[] : array where the address will be stored
//               address_size : size of the array defined in main.c
//
//
//  *************************************************************/

#include <stdio.h>
#include "record.h"

extern int debugmode;

void getaddress (char address[], int address_size)
{
    char buffer;
    int counter;

    for (counter = 0; (((buffer = getchar()) != '$') && (counter < address_size)); counter++)
    {
        address[counter] = buffer;
    }
    
    address[counter] = '\0';
}

