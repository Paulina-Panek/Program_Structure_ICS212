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

/*****************************************************************
//  Function name: writefile
// 
//  DESCRIPTION:   Saves to .gif from unsigned char array
// 
//  Parameters:    data (unsigned char[]) : contains data to  be written
//                 size (int) : size of each element in data array
//                     filename (char[]) : name of the output file
//
//  Return values:  0 : success
//                 -1 : no file written
//
//  ****************************************************************/
int writefile(unsigned char data[], int size, char filename[])
{
    FILE *fp;
    int rtrn_val;

    fp = fopen(filename, "w");
    if (fp == 0)
    {
        rtrn_val = -1;
    }
    else
    {   
        rtrn_val = 0; 
        fwrite(data, size, 4000, fp);
        fclose(fp);
    }
    return(rtrn_val);
}
