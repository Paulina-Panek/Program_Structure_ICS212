/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 25th, 2018
//
//  FILE:        record.h
//
//  DESCRIPTION:
//  Header file that defines structure of entries in the database
//  Also contains all the function prototypes and needed libraries
//  *************************************************************/

#ifndef RECORD
#define RECORD

typedef struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
} record;

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addRecord (struct record**, int, char [], char []);

int printRecord (struct record*, int);

void printAllRecords (struct record*);

int deleteRecord (struct record**, int );

void getaddress (char[], int);

