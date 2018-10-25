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
    int rtrn_val, value, record_num;

    rtrn_val = -1;
    record_num  = 0;

    if (start != NULL)
    {
        temp_old = start;
        temp_new = start->next;
        value = start->accountno;
        record_num = 1;

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
            record_num++;
        }

        while (value == uaccountno)
        {
            rtrn_val = 0;

            if (record_num > 1)
            {
                printf("Account No:\t%d\n", temp_new->accountno);
                printf("Name:\t%s", temp_new->name);
                printf("Address:\n%s\n", temp_new->address);
                
                temp_old = temp_new;

                if (temp_old != NULL)
                    temp_new = temp_old->next;
        
                if (temp_new != NULL)
                    value = temp_new->accountno;

                if (temp_new == NULL)
                    value = uaccountno + 1;
            }

            if (record_num == 1)
            {
                printf("Account No:\t%d\n", temp_old->accountno);
                printf("Name:\t%s", temp_old->name);
                printf("Address:\n%s\n", temp_old->address);
       
            temp_old = temp_new;
        
            if (temp_new != NULL)
                value = temp_new->accountno;

            if (temp_old != NULL)
                temp_new = temp_old->next;

            if (temp_old == NULL)
                value = uaccountno + 1;
            }

       }

    }
return(rtrn_val);

}

