/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    7b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5th, 2018
//
//  FILE:        printinfor.c
//
//  DESCRIPTION:
//  Prints header information about .gif
//  *************************************************************/

#include "header.h"

int printinfor(unsigned char data[])
{
    int i;

    printf("Width: \n");
    for (i = 7; i <= 6; i--)
    {
        printf("%u", data[i]);
    }
    printf("\n\n");

    printf("Height: \n");
    for (i = 8; i <= 9; i++)
    {
        printf("%u", data[i]);
    }
    printf("\n\n");

    printf("Color 1: \n");
    for (i = 13; i <= 15; i++)
    {
        printf("R: %x\n", data[i]);
        printf("G: %x\n", data[i]);
        printf("B: %x\n", data[i]);

    }
    printf("\n\n");

 
    printf("Color 2: \n");
    for (i = 16; i <= 18; i++)
    {
        printf("R: %x\n", data[i]);
        printf("G: %x\n", data[i]);
        printf("B: %x\n", data[i]);

    }
    printf("\n\n");

    printf("Colori 3: \n");
    for (i = 19; i <= 21; i++)
    {
        printf("R: %x\n", data[i]);
        printf("G: %x\n", data[i]);
        printf("B: %x\n", data[i]);

    }
    printf("\n\n");

    printf("Colori 4: \n");
    for (i = 22; i <= 24; i++)
    {
        printf("R: %x\n", data[i]);
        printf("G: %x\n", data[i]);
        printf("B: %x\n", data[i]);

    }
    printf("\n\n");





    return(0);
}
