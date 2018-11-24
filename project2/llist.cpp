/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    project2
////
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 22nd, 2018
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//  Contains function definitions for class llist.
//  *************************************************************/

#include "record.h"
#include "llist.h"

/***************************************************************
//  Function name: readfile
// 
//   DESCRIPTION:   Reads struct record data from a file and stores
//                  them as an array of struct record
//                  
//   Return values:  0 : success
//                   1 : error opening the file
// 
//  ****************************************************************/ 

int llist :: readfile()
{

    char name[25], address[80], buffer;
    int accountno, eof_check, val, counter;
  
    ifstream myfile;
    myfile.open(filename);

    eof_check = 0;

    if (myfile.is_open() == false)
    {
        val = 0;
    }

    while(myfile.getline(name, 25))
    {
        counter = 0; 

        myfile >> accountno;
        myfile.get(buffer);

        while (counter < 80)
        {
            myfile.get(address[counter]);
 
            if (address[counter] == '\n' && address[counter - 1] == '\n')
            {
                address[counter] = 0;
                counter = 80;
            }
            counter++;
        }
       
        eof_check ++;
          
            if (debugmode == 1)
            { 
                std::cout << "***DEBUG (inside readfile) START***\n";
                std::cout << "\n"; 
                std::cout << "Function Called:\t addRecord\n\n";
                std::cout << "Parameters Passed:\n";
                std::cout << "Account number:\t%d\n" << accountno;
                std::cout << "Name:\t%s" << name;
                std::cout << "Address:\n";
                std::cout << "\n\n" << address;
                std::cout << "***DEBUG (inside readfile) END***\n";
            }

            addRecord(accountno, name, address);

        }
    myfile.close();
    return(val);
}

/***************************************************************
//  Function name: writefile
// 
//   DESCRIPTION:   Writes or updates a file with struct record data
//                  from an array
//                  
//   Return values:  0 : success
//                   1 : error opening the file
// 
//  ****************************************************************/

void llist :: writefile()
{

    struct record * ptr;

    ofstream myfile;
    myfile.open("database.txt", ios::trunc);

    if (myfile.is_open() == true)
    {
        while (ptr != NULL)
        {
            myfile << ptr->accountno;
            myfile << ptr->name;
            myfile << ptr->address;
            myfile << "$\n\n\n\n";

            ptr = ptr->next;
        }
        
        myfile.close();
    }
}

record* llist :: reverse(record*)
{

return(0);
}

void llist :: cleanup()
{
    struct record * next, *prev;
    
    next = start;

    while (next != NULL)
    {
        prev = next;
        next = next->next;
        delete(prev); 
    }
}

llist :: llist()
{
    start = NULL;

    strcpy(filename, "database.txt");
    readfile();
}

llist :: llist(char input[])
{
    start = NULL;
    strcpy(filename, input);
    readfile();
}

llist :: ~llist()
{
    writefile();
    cleanup();
}

int llist :: addRecord (int uaccountno, char uname[], char uaddress[])
{
    struct record *temp_prev, *temp_next, *new_list;
    int value, rtrn;

    rtrn = -1;

    if (start == NULL)
    {
        temp_prev = new record;
        temp_prev->accountno = uaccountno;
        strcpy(temp_prev->name, uname); 
        strcpy(temp_prev->address, uaddress);
        temp_prev->next = NULL;
        start = temp_prev;
        rtrn = 0;
    }

    else
    {
        new_list = new record;
        new_list->accountno = uaccountno;
        strcpy(new_list->name, uname); 
        strcpy(new_list->address, uaddress);
        
        value = start->accountno;
        temp_prev = start;
        temp_next = temp_prev->next;
        
        if (value >= uaccountno)
        {   
            new_list->next = start;
            start = new_list;
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

int llist :: printRecord (int uaccountno)
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
                std::cout << "Account No:\t\n" << temp_new->accountno;
                std::cout << "Name:\t" << temp_new->name;
                std::cout << "Address:\n\n" << temp_new->address;
                
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

int llist :: deleteRecord(int uaccountno)
{
    struct record * temp_old, *temp_new;
    int rtrn_val, value, record_num;

    rtrn_val = -1;
    record_num = 0;

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

            if (record_num>1)
            {
                    temp_old->next = temp_new->next;
                    free(temp_new);

                    if (temp_old != NULL)
                        temp_new = temp_old->next;
        
                    if (temp_new != NULL)
                         value = temp_new->accountno;
                    else
                        value = uaccountno + 1;
            }

            if (record_num == 1)
            {
                    start = temp_new;
                    delete(temp_old);
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

void llist :: reverse()
{
}
