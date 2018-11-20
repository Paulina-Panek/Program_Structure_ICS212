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
// //   Return values:  0 : success
// //                   1 : error
// // 
// //  ****************************************************************/ 

int  main()
{

    int choice, running, accountno, rtrn, rtrnd, rtrnpr, main_rtrn;
    char name[25], address[80];
    struct record * start;

    start = NULL;
    running = 1;

    llist begin;

if (main_rtrn == 0)
{
    if (debugmode == 1)
    {
        cout << "***DEBUG START***\n";
        cout << "\n";       
 
        cout << "Function Called:\t readfile\n\n";
        cout << "Parameters Passed:\n";
        cout << "Address of start pointer:\t%p\n" << (void*)&start;
        cout << "Hardcoded txt file:\tdatabase.txt\n";
      
        cout << "\n";        
        cout << "***DEBUG END****\n";
    }

    readfile(&start, "database.txt");

    while (running == 1)
    {
        cout << "\n\nChoose what you would like to do:\n";
        cout << "Option 1: Add a New Record\n";
        cout << "Option 2: Print Record by Account Number\n";
        cout << "Option 3: Print All Records\n";
        cout << "Option 4: Delete Record by Account Number\n";
        cout << "Option 5: Quit Program\n";

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            cout << "You chose Option 1\n";    
            
            cout << "Please enter the account number of the new record:\n";
            cout << "ONLY INTEGERS 0-9 ALLOWED, NO CHARACTERS\n";
            scanf("%d", &accountno);
           
            cout << "Please enter the name of the new record:\n";
            std::cin.getline(name, 25);

            cout << "Please enter the address of the new record:\n";
            cout << "Type $ after you are done and hit enter.\n";
            std::cin.getline(address, 80, '$');        

            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
               
                cout << "Function Called:\t getaddress\n\n";
                cout << "Parameters Passed:\n";
                cout << "Address:\n%s\n" <<  address;
                cout << "(Max) Size of address:\t%lu\n\n" <<  sizeof address;
 
                cout << "Function Called:\t addRecord\n\n";
                cout << "Parameters Passed:\n";
                cout << "Address of start pointer:\t%p\n" << (void*)&start;
                cout << "Account number:\t%d\n" << accountno;
                cout << "Name:\t%s" << name;
                cout << "Address:\n";
                cout << "%s\n\n" << address;
                cout << "\n";  
 
                cout << "***DEBUG END***\n";
                cout << "\n";         
           }

           rtrn = begin.addRecord(accountno, name, address); 
           if (rtrn == 0)
               cout << "\nRecord added successfully\n";
           if (rtrn == -1)
               cout << "\nRecord NOT added.\n";
           break;

        case 2:
            cout << "You chose Option 2\n"; 
            
            cout << "Please enter the account number of the record you want to print:\n";
            scanf("%d", &accountno);
            
            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
 
                cout << "Function Called:\t printRecord\n\n";
                cout << "Parameters Passed:\n";
                cout << "Start pointer:\t%p\n" << (void*)start;
                cout << "Account number:\t%d\n\n" << accountno;
              
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";        
           }
           
            rtrnpr = begin.printRecord(accountno);
            if (rtrnpr == -1)
                cout << "No Record Found.\n";
            break;
        
        case 3:
            cout << "You chose Option 3\n";

            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
 
                cout << "Function Called:\t printAllRecord\n\n";
                cout << "Address of start pointer:\t%p\n" << (void*)&start;
                
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";        
 
            }
 
            //*printAll replace*//
            break;

        case 4:
            cout << "You chose Option 4\n";
            cout << "Please enter the account number to be deleted:\n";
            
            scanf("%d", &accountno);

            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
   
                cout << "Function Called:\t deleteRecord\n\n";
                cout << "Parameters Passed:\n";
                cout << "account number:\t%d\n\n" <<  accountno;
 
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";        
            }

            rtrnd = begin.deleteRecord(accountno);
            if (rtrnd == 0)
                cout << "\nRecord Deleted Successfully.\n";
            if (rtrnd == -1)
                cout << "\nNo Record Found\n";
            break;

        case 5:
            cout << "You chose Option 5\n"; 
 
            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
 
                cout << "Function Called:\t none\n";
                cout << "Parameters Passed:\tnone\n\n";
            
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";         
            }

            cout << "Exiting program.\n\n";
            running = 0;
            break;

        default:
            cout << "Invalid choice.\n\n";   
            break;
    }
}
    if (debugmode == 1)
    {
        cout << "***DEBUG START***\n";
        cout << "\n";       
 
        cout << "Function Called:\t writefile\n\n";
        cout << "Start pointer:\t%p\n" << (void*)start;
        cout << "Hardcoded txt file:\tdatabase.txt\n";
                
        cout << "\n";        
        cout << "***DEBUG END****\n";
    }

writefile(start, "database.txt");
}
return(main_rtrn);
}
