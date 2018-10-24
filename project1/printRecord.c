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
//  FILE:        printRecord.c
//
//  DESCRIPTION:
//  Prints record by accountno
//
//  Parameters:  
//               start - pointer to the first record
//               uaccountno - account number of the record to be printed
//
//  Return value: 
//               -1 - no record with such accountno exists
//                0 - record(s) have been printed
//  *************************************************************/


#include "record.h"

extern int debugmode;

int printRecord (struct record * start, int uaccountno)
{
    struct record * temp_old, *temp_new;
    int rtrn_val, value;

    rtrn_val = -1;
    printf("I'm inside function Start pointer:\t%p\n", (void*)start);

    if (start != NULL)
    {
        temp_old = start;
        value = start->accountno;

        while (value < uaccountno)
        { 
            temp_new = temp_old->next;

            if (temp_new == NULL)
            {
                value = uaccountno + 1;
            }
            else
            {
                value = temp_new->accountno;

                if (value < uaccountno)
                {
                    temp_old = temp_new;
                }
            }
             
        }
        while (value == uaccountno)
        {
            rtrn_val = 0;
            
            printf("Account No:\t%d\n", uaccountno);
            printf("Name:\t%s\n", temp_new->name);
            printf("Address:\t%s\n", temp_new->address);
                if (temp_new != NULL)
                    value = temp_new->accountno ;
                else
                    value = uaccountno + 1;
        }

    }
return(rtrn_val);

}

