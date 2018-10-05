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
//  FILE:        record.h
//
//  DESCRIPTION:
//  Header file that defines structure of entries that the functions
//  will read and write.
//  *************************************************************/

#ifndef RECORD
#define RECORD

typedef struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
} record;

#endif
