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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//  Contains function definitions.
//  *************************************************************/

int llist :: readfile()
{
}

void llist :: writefile()
{
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
