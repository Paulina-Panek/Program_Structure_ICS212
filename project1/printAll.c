/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    Project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 25th, 2018
//
//  FILE:        printAll.c
//
//  DESCRIPTION:
//  Prints all records
//
//  Parameters:  
//               start - pointer to the first record
//
//  *************************************************************/


#include "record.h"

extern int debugmode;

void printAllRecords (struct record * start)
{
    struct record *temp;
    temp = start;

    while (temp != NULL)
        {           
            printf("Account No:\t%d\n", temp->accountno);
            printf("Name:\t%s", temp->name);
            printf("Address:\n%s\n\n", temp->address);
            temp = temp->next;
        }
}

