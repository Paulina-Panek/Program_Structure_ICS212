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
//  FILE:        record.h
//
//  DESCRIPTION:
//  Header file that defines structure of entries in the database
//  Also contains all the function prototypes
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

int addRecord (struct record**, int, char [], char []);

int printRecord (struct record*, int);

void printAllRecords (struct record*);

int deleteRecord (struct record**, int );

void getaddress (char[], int);

