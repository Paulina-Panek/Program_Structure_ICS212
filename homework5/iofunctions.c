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

#include<stdio.h>
#include "record.h"

int readfile( struct record accarray[ ], int* numcust, char filename[ ] );
int writefile( struct record accarray[ ], int numcust, char filename[ ] );

int readfile( struct record accarray[], int* numcust, char filename[])
{
    FILE * inf;
    int i;

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        return(1);    
    }
    else
    {
        while (i = 0; feof == 0, i++)
        { 
        fscanf(filename, "%d", &accarray.accountno[i]);
        fgets(&accarray.name[i], 20, filename);
        fgets(&accarray.address[i], 80, filename);
        }

    fclose(filename);
    *numcust = i;    
    
    return(0);
    } 
}


int writefile( struct record accarray[], int numcust, char filename[] )
{

}
