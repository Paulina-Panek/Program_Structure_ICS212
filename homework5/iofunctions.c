/***************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 6th, 2018
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//  Contains readfile and writefile functions. Note the functions
//  do not contain terminal I/O functions. 
//  *************************************************************/

#include <string.h>
#include <stdio.h>
#include "record.h"
#include "prototypes.h"

int readfile( struct record accarray[], int* numcust, char filename[])
{
    FILE * inf;
    int i, eof_check, account_temp;
   
    i = 0;
    eof_check = 0;

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        fclose(inf);
        *numcust = i;    
        return(1);    
    }
    else
    {
        for (i = 0; (feof(inf) == 0 && eof_check == 0); i++)
        { 
            if (fscanf(inf, "%d\n", &account_temp) != 1)
            {
                eof_check = 1;
                i--;
            }
            else
            {
                accarray[i].accountno = account_temp;
                fgets(accarray[i].name, 20, inf);
                fgets(accarray[i].address, 80, inf);
            }
        }
    fclose(inf);
    *numcust = i;    
    
    return(0);
    } 
}

int writefile( struct record accarray[], int numcust, char filename[] )
{
    FILE * outf;
    int i;

    outf = fopen(filename, "w+");

    if (outf == NULL)
    {
        return(1);
    }
    else
    {
        for (i =0; i < numcust; i++)
        {
        fprintf(outf,"%d\n", accarray[i].accountno);
        fprintf(outf, "%s", accarray[i].name);
        fprintf(outf, "%s", accarray[i].address);
        fprintf(outf, "\n");
    }
    fclose(outf);
    numcust = i;
    
    return(0);
    }
}
