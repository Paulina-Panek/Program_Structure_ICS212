/*************************************************************
// //  NAME:        Paulina Panek
// //
// //  HOMEWORK:    project2
// //
// //  CLASS:       ICS 212
// //
// //  INSTRUCTOR:  Ravi Narayan
// //
// //  DATE:        Nov 22nd, 2018
// //
// //  FILE:        main.cpp
// //
// //  DESCRIPTION:
// //  This is a user interface that allows to add, remove, and 
// //  print records in a database storing account numbers, names,
// //  and addresses.
// //
***********************************************************/

#include "record.h"

/***************************************************************
//      Function name: main
// 
// //   DESCRIPTION:   Reads struct record data from a file, allows user
// //                  to add/delete records, updates the file. Contains
// //                  debug print statements
// // 
// //   Parameters:    argc : number of arguments when calling program
// //                             
// //                  argv : sets debug mode on and off
// //                  
// //   Return values:  0 : success
// //                   1 : error
// // 
// //  ****************************************************************/ 

int  main(int argc, char *argv[])
{

    int result, choice, running, accountno, rtrn, rtrnd, rtrnpr, main_rtrn;
    char keyword[5], name[25], address[80];
    struct record * start;

    start = NULL;
    running = 1;

    if (argc > 1)
    {
        strcpy(keyword, "debug");
        result = strcmp(argv[1], keyword);
        
        if ((argc < 3) && (result == 0))
        {
             debugmode = 1;
             main_rtrn = 0;
        }

        else 
            {
                printf("Wrong program call.\n");
                main_rtrn = -1;
            }   
    }
    else
    {
         debugmode = 0;
         main_rtrn = 0;
    }
if (main_rtrn == 0)
{
    if (debugmode == 1)
    {
        printf("***DEBUG START***\n");
        printf("\n");       
 
        printf("Function Called:\t readfile\n\n");
        printf("Parameters Passed:\n");
        printf("Address of start pointer:\t%p\n", (void*)&start);
        printf("Hardcoded txt file:\tdatabase.txt\n");
              
        printf("\n");        
        printf("***DEBUG END****\n");
    }

    readfile(&start, "database.txt");

    while (running == 1)
    {
        printf("\n\nChoose what you would like to do:\n");
        printf("Option 1: Add a New Record\n");
        printf("Option 2: Print Record by Account Number\n");
        printf("Option 3: Print All Records\n");
        printf("Option 4: Delete Record by Account Number\n");
        printf("Option 5: Quit Program\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You chose Option 1\n");    
            
            printf("Please enter the account number of the new record:\n");
            printf("ONLY INTEGERS 0-9 ALLOWED, NO CHARACTERS\n");
            scanf("%d", &accountno);
           
            printf("Please enter the name of the new record:\n");
            getchar();
            fgets(name, sizeof name, stdin);

            printf("Please enter the address of the new record:\n");
            printf("Type $ after you are done and hit enter.\n");
            getaddress(address, sizeof address);           

            if (debugmode == 1)
            {
                printf("\n");   
                printf("***DEBUG START***\n");
                printf("\n");       
               
                printf("Function Called:\t getaddress\n\n");
                printf("Parameters Passed:\n");
                printf("Address:\n%s\n", address);
                printf("(Max) Size of address:\t%lu\n\n", sizeof address);
 
                printf("Function Called:\t addRecord\n\n");
                printf("Parameters Passed:\n");
                printf("Address of start pointer:\t%p\n", (void*)&start);
                printf("Account number:\t%d\n", accountno);
                printf("Name:\t%s", name);
                printf("Address:\n");
                printf("%s\n\n", address);
                printf("\n");  
 
                printf("***DEBUG END***\n");
                printf("\n");         
           }

           rtrn = addRecord(&start, accountno, name, address); 
           if (rtrn == 0)
               printf("\nRecord added successfully\n");
           if (rtrn == -1)
               printf("\nRecord NOT added.\n");
           break;

        case 2:
            printf("You chose Option 2\n"); 
            
            printf("Please enter the account number of the record you want to print:\n");
            scanf("%d", &accountno);
            
            if (debugmode == 1)
            {
                printf("\n");   
                printf("***DEBUG START***\n");
                printf("\n");       
 
                printf("Function Called:\t printRecord\n\n");
                printf("Parameters Passed:\n");
                printf("Start pointer:\t%p\n", (void*)start);
                printf("Account number:\t%d\n\n", accountno);
              
                printf("\n");  
                printf("***DEBUG END***\n");
                printf("\n");        
           }
           
            rtrnpr = printRecord(start, accountno);
            if (rtrnpr == -1)
                printf("No Record Found.\n");
            break;
        
        case 3:
            printf("You chose Option 3\n");

            if (debugmode == 1)
            {
                printf("\n");   
                printf("***DEBUG START***\n");
                printf("\n");       
 
                printf("Function Called:\t printAllRecord\n\n");
                printf("Address of start pointer:\t%p\n", (void*)&start);
                
                printf("\n");  
                printf("***DEBUG END***\n");
                printf("\n");        
 
            }
 
            printAllRecords(start);
            break;

        case 4:
            printf("You chose Option 4\n");
            printf("Please enter the account number to be deleted:\n");
            
            scanf("%d", &accountno);

            if (debugmode == 1)
            {
                printf("\n");   
                printf("***DEBUG START***\n");
                printf("\n");       
   
                printf("Function Called:\t deleteRecord\n\n");
                printf("Parameters Passed:\n");
                printf("account number:\t%d\n\n", accountno);
 
                printf("\n");  
                printf("***DEBUG END***\n");
                printf("\n");        
            }

            rtrnd = deleteRecord(&start, accountno);
            if (rtrnd == 0)
                printf("\nRecord Deleted Successfully.\n");
            if (rtrnd == -1)
                printf("\nNo Record Found\n");
            break;

        case 5:
            printf("You chose Option 5\n"); 
 
            if (debugmode == 1)
            {
                printf("\n");   
                printf("***DEBUG START***\n");
                printf("\n");       
 
                printf("Function Called:\t none\n");
                printf("Parameters Passed:\tnone\n\n");
            
                printf("\n");  
                printf("***DEBUG END***\n");
                printf("\n");         
            }

            printf("Exiting program.\n\n");
            running = 0;
            break;

        default:
            printf("Invalid choice.\n\n");   
            break;
    }
}
    if (debugmode == 1)
    {
        printf("***DEBUG START***\n");
        printf("\n");       
 
        printf("Function Called:\t writefile\n\n");
        printf("Start pointer:\t%p\n", (void*)start);
        printf("Hardcoded txt file:\tdatabase.txt\n");
                
        printf("\n");        
        printf("***DEBUG END****\n");
    }

writefile(start, "database.txt");
}
return(main_rtrn);
}
