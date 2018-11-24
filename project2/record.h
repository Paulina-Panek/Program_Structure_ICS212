/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 22nd, 2018
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

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#define debugmode 1

#endif
