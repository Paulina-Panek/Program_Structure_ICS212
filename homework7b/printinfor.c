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
    printf("%u", data[7]);
    printf("%u", data[6]);
    printf("\n\n");

    printf("Height: \n");
    for (i = 8; i <= 9; i++)
    {
        printf("%u", data[i]);
    }
    printf("\n\n");

    printf("Color 1: \n");
    printf("R: %x\n", data[13]);
    printf("G: %x\n", data[14]);
    printf("B: %x\n", data[15]);

    printf("\n\n");

 
    printf("Color 2: \n");
    printf("R: %x\n", data[16]);
    printf("G: %x\n", data[17]);
    printf("B: %x\n", data[18]);

    printf("\n\n");

    printf("Colori 3: \n");
    printf("R: %x\n", data[19]);
    printf("G: %x\n", data[20]);
    printf("B: %x\n", data[21]);

    printf("\n\n");

    printf("Colori 4: \n");
    printf("R: %x\n", data[22]);
    printf("G: %x\n", data[23]);
    printf("B: %x\n", data[24]);

    printf("\n\n");

    return(0);
}
