/*************************************************************
// //  NAME:        Paulina Panek
// //
// //  HOMEWORK:    3b
// //
// //  CLASS:       ICS 212
// //
// //  INSTRUCTOR:  Ravi Narayan
// //
// //  DATE:        September 22nd, 2018
// //
// //  FILE:        main.c
// //
// //  DESCRIPTION:
// //   
// // 
// //
***********************************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"

int debug;

int  main(int argc, char *argv[])
{

int result, choice, running, accountno;
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
             debug = 1;
        }

        else 
            {
                printf("Wrong program call.\n");
            }   
    }
    else
    {
         debug = 0;
    }

while (running == 1)
{
    printf("Choose what you would like to do:\n");
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
            scanf("%d", &accountno);
           
            printf("Please enter the name of the new record:\n");
            getchar();
            fgets(name, sizeof name, stdin);

            printf("Please enter the address of the new record:\n");
            printf("Type $ after you are done and hit enter.\n");
            getaddress(address, sizeof address);           

            addRecord(&start, accountno, name, address); 
            
            printf("\n");
            break;

        case 2:
            printf("You chose Option 2\n"); 
            
            printf("Please enter the account number of the record you want to print:\n");
            scanf("%d", &accountno);
            
            printRecord(start, accountno);

            break;
        
        case 3:
            printf("You chose Option 3\n");

            printAllRecords(start);
            break;

        case 4:
            printf("You chose Option 4\n");
            printf("Please enter the account number to be deleted:\n");
            
            scanf("%d", &accountno);
            deleteRecord(&start, accountno);
            break;

        case 5:
            printf("You chose Option 5\n"); 
            printf("Exiting program.\n");
            running = 0;
            break;

        default:
            printf("Invalid choice.\n");   
            break;
    }

}

return(0);
}

void getaddress (char address[], int address_size)
{
    char buffer;
    int counter;

    for (counter = 0; (((buffer = getchar()) != '$') && (counter < address_size)); counter++)
    {
        address[counter] = buffer;
    }
    
    address[counter] = '\0';

}
