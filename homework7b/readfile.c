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
//  FILE:        readfile.c
//
//  DESCRIPTION:
//  Function that reads binary .gif data
//  *************************************************************/

#include "header.h"

int readfile(unsigned char data[], int* size_ptr, char filename[])
{
    FILE *fp;
    int size;

    size = *size_ptr;
    fp = fopen(filename, "r");

    fread(data, size, 4000, fp);

    fclose(fp);

    return(0);
}
