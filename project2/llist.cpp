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
    int account_temp, accountno, eof_check, size, val, remaining;
    
    FILE *inf = fopen(filename, "a+");
                
    eof_check = 0;

    if(inf == NULL)
    {
        val = 0;
    }

    while(eof_check != 1)
    {
        if (fscanf(inf, "%d\n", &account_temp) != 1)
        {
            eof_check = 1;
        }
        else
        {
            accountno = account_temp;
            fgets(name, 25, inf);
           
            for (size = 0;  ((buffer = (fgetc(inf))) != '$') && (size < 80); size++) 
            {   
                address[size] = buffer;
            }
           
             val = 0;
            
             for ((remaining = 79 - (size+1)); remaining != 80; remaining++)
            { 
                address[remaining] = ' ';
            }
            
            if (debugmode == 1)
            { 
                std::cout << ("***DEBUG (inside readfile) START***\n";
                std::cout << "\n"; 
                std::cout << "Function Called:\t addRecord\n\n";
                std::cout << "Parameters Passed:\n";
                std::cout << "Address of start pointer:\t%p\n" << (void*)start_ptr;
                std::cout << "Account number:\t%d\n" << accountno;
                std::cout << "Name:\t%s" << name;
                std::cout << "Address:\n";
                std::cout << "\n\n" << address;
                std::cout << "***DEBUG (inside readfile) END***\n";
            }

            addRecord(accountno, name, address);

        }
    }
    fclose(inf);
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
//* FIGURE OUT WHERE THE START IS (ptr) *//

    int value;
    struct record * ptr;

    ofstream.myfile;
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
}

void llist :: cleanup()
{
}

int llist :: addRecord (int, char[], char[])
{
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

int llist :: printRecord (int)
{
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
        
}

int llist :: deleteRecord(int)
{
int deleteRecord (struct record** start_ptr, int uaccountno)
{
    struct record * temp_old, *temp_new, *start;
    int rtrn_val, value, record_num;

    start = *start_ptr;
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
}

void llist :: reverse()
{
}
