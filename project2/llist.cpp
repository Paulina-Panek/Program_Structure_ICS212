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

    string  name, address, account_str, buffer;
    int accountno, val;
  
    ifstream myfile;
    myfile.open(filename);

    val = 1;

    if (myfile.is_open() == false)
    {
        val = 0;
    }

    while(val == 1 && !myfile.eof())
    {
        account_str.clear();
        name.clear();
        address.clear();

        getline(myfile, account_str, '\n');
        accountno = atoi(account_str.c_str());
        getline(myfile, name, '\n');
        getline(myfile, address, '$');
        if (!myfile.eof())
	    getline(myfile, buffer, '\n');
         
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

            addRecord(accountno, (char*)(name.c_str()), (char*)(address.c_str()));

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
    ptr = start;

    myfile.open(filename);

    if (myfile.is_open() == true)
    {
        while (ptr != NULL)
        {
            myfile << ptr->accountno << endl;
            myfile << ptr->name << endl;
            myfile << ptr->address << endl;
            myfile << "$";

            ptr = ptr->next;
            if (ptr != NULL)
                {
                    myfile << endl;
                }
        }
        
        myfile.close();
    }
}

/***************************************************************
//  Function name: llist::reverse
// 
//   DESCRIPTION:   Reverses linked list
//
//   PARAMETERS:    record * mylist - pointer to linked list
//
//   RETURN VALUE:  Reversed linked list
//                  
//  ****************************************************************/

record* llist :: reverse(record* mylist)
{
    struct record * ptr;

    if ((mylist->next) == NULL)
    {
        start = mylist;
    }
    else
    {
        reverse(mylist->next);
        ptr = mylist->next;
        ptr->next = mylist;
        mylist->next = NULL;
    }
    return(mylist);
}

/***************************************************************
//  Function name: llist::cleanup
// 
//   DESCRIPTION:   Deallocates space when we leave the program
//                  
//  ****************************************************************/

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

/***************************************************************
//  Function name: llist::llist()
// 
//   DESCRIPTION:   Constructor, initializes start and calls readfile
//                  
//  ****************************************************************/

llist :: llist()
{
    start = NULL;

    strcpy(filename, "database.txt");
    readfile();
}

/***************************************************************
//  Function name: llist::llist(char)
// 
//   DESCRIPTION:   Constructor, initializes start and calls readfile
//                  
//  ****************************************************************/

llist :: llist(char input[])
{
    start = NULL;
    strcpy(filename, input);
    readfile();
}

/***************************************************************
//  Function name: llist::~llist()
// 
//   DESCRIPTION:   Destructor, calls for writing file and cleaning up
//                  the memory
//                  
//  ****************************************************************/

llist :: ~llist()
{
    writefile();
    cleanup();
}

/****************************************************************
//  Function name : addRecord
//
//  DESCRIPTION:
//  Adds a record to the linked list; sorted by accountno
//
//  Parameters:  
//               uaccountno - account number of the record to be added
//               uname - user name
//               uaddress - user address
//  Return value: 
//                0 - record has been added
//                -1 - record not added
//  *************************************************************/

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

/****************************************************************
//  Function name: llist:: printRecord
//  DESCRIPTION:
//  Prints record by accountno
//
//  Parameters:  
//               uaccountno - account number of the record to be printed
//
//  Return value: 
//               -1 - no record with such accountno exists
//                0 - record(s) have been printed
//  *************************************************************/

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
                std::cout << "Account No:\t" << temp_new->accountno << endl;
                std::cout << "Name:\t" << temp_new->name << endl;
                std::cout << "Address:" << temp_new->address << endl;
                
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
                std::cout << "Account No:\t" << temp_old->accountno << endl;
                std::cout << "Name:\t" << temp_old->name << endl;
	        std::cout << "Address:\t" << temp_old->address << endl;
       
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
/*******************************************************************
//  Function Name : llist::deleteRecord
//
//  DESCRIPTION:
//  Function that deletes record that has the provided account number
//
//  Parameters:  
//             uaccountno - account number of the record to be deleted
//
//  Return value: 
//               -1 - no record has been deleted
//                0 - record(s) have been deleted
//  *************************************************************/

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

/***************************************************************
//  Function name: llist::reverse()
// 
//   DESCRIPTION:   Reverses list
//                  
//  ****************************************************************/

void llist :: reverse()
{
    if (start == NULL)
    {
        cout << "No records in the database" << endl;
    }
    else
    {
        reverse (start);
    }
}

/***************************************************************
//  Function name: ostream & operator << 
// 
//   DESCRIPTION:   Operator overload for printing all records
//                  
//  ****************************************************************/

ostream & operator << (ostream &out, const llist &mylist)
{
    struct record * ptr;

    ptr = mylist.start;
    
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            cout << ptr->accountno << endl;
            cout << ptr->name << endl;
            cout << ptr->address << endl;

            ptr = ptr->next;
         }

    }
    return(out);
}
