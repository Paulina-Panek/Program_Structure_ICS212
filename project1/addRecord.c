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
//  FILE:        addRecord.c
//
//  DESCRIPTION:
//  Adds a record to the linked list; sorted by accountno
//
//  Parameters:  
//               start - pointer to the first record
//               uaccountno - account number of the record to be deleted
//
//  Return value: 
//                0 - record has been added
//                -1 - record not added
//  *************************************************************/

#include "record.h"

extern int debugmode;

int addRecord (struct record ** start_ptr, int uaccountno, char uname[], char uaddress[])
{
    struct record *temp_prev, *temp_next, *new_list, *start;
    int value, rtrn;

   rtrn = -1;
   start = *start_ptr; 

    if (start == NULL)
    {
        start = (struct record*)malloc(sizeof(struct record));
        start->accountno = uaccountno;
        strcpy(start->name, uname); 
        strcpy(start->address, uaddress);
        start->next = NULL;
        *start_ptr = start;
        rtrn = 0;
    }

    else
    {
        new_list = (struct record*)malloc(sizeof(struct record));
        new_list->accountno = uaccountno;
        strcpy(new_list->name, uname); 
        strcpy(new_list->address, uaddress);
        
        value = start->accountno;
        temp_prev = start;
        temp_next = temp_prev->next;
        
        if (value >= uaccountno)
        {   
            new_list->next = start;
            *start_ptr = new_list;
        }
        
        else
        {
            while (value < uaccountno)
            {
                temp_next = temp_prev->next;
                if (temp_next == NULL)
                    value = uaccountno;
                else
                {  
                    value = temp_next->accountno;
            
                    if (value < uaccountno)
                        temp_prev = temp_next;
                }
            }
            temp_prev->next = new_list;
            new_list->next = temp_next;
            rtrn = 0;
        }
   }
return(rtrn);
}


