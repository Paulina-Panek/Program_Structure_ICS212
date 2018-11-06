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

/*****************************************************************
//  Function name: readfile
// 
//  DESCRIPTION:   Reads from .gif to unsigned char array
// 
//  Parameters:    data (unsigned char[]) : array where read data stored
//                 size (int*) : pointer to size of each element in data array
//                 filename (char[]) : name of the input file
//
//  Return values:  0 : success
//                 -1 : no file read
//
//  ****************************************************************/

int readfile(unsigned char data[], int* size_ptr, char filename[])
{
    FILE *fp;
    int size, rtrn;

    size = *size_ptr;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        rtrn = -1;
    }
    else
    {
        fread(data, size, 4000, fp);
        fclose(fp);
        rtrn = 0;
    }
    return(rtrn);
}
