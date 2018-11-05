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
//  FILE:        wriitefile.c
//
//  DESCRIPTION:
//  Function that writes binary .gif data
//  *************************************************************/

#include "header.h"

int writefile(unsigned char data[], int size, char filename[])
{
    FILE *fp;

    fp = fopen(filename, "w");
    
    fwrite(data, size, 4000, fp);
    fclose(fp);

    return(0);
}
