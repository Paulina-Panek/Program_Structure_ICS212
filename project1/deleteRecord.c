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
//  FILE:        deleteRecord.c
//
//  DESCRIPTION:
//  Function that deletes record that has the provided account number
//
//  Parameters:  
//               start - pointer to the first record
//               uaccountno - account number of the record to be deleted
//
//  Return value: 
//               -1 - no record has been deleted
//                0 - record(s) have been deleted
//  *************************************************************/


#include "record.h"

extern int debugmode;

int deleteRecord (struct record** start_ptr, int uaccountno)
{
    struct record * temp_old, *temp_new, *start;
    int rtrn_val, value;

start = *start_ptr;
rtrn_val = -1;

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
            temp_old->next = temp_new->next;
            free(temp_new);
            rtrn_val = 0;
            temp_new = temp_old->next;

                if (temp_new != NULL)
                    value = temp_new->accountno ;
                else
                    value = uaccountno + 1;
        }

    }
return(rtrn_val);
}

