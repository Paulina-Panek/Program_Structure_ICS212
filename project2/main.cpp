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
#include "llist.h"
using namespace std;

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
    char name[25], address[80], garbage[10];

    llist begin;

    running = 1;
    main_rtrn = 0;

if (main_rtrn == 0)
{
    if (debugmode == 1)
    {
        cout << "***DEBUG START***\n";
        cout << "\n";       
 
        cout << "Function Called:\t readfile\n\n";
        cout << "Parameters Passed:\n";
        cout << "Hardcoded txt file:\tdatabase.txt\n";
      
        cout << "\n";        
        cout << "***DEBUG END****\n";
    }

    while (running == 1)
    {
        cout << "\n\nChoose what you would like to do:\n";
        cout << "Option 1: Add a New Record\n";
        cout << "Option 2: Print Record by Account Number\n";
        cout << "Option 3: Print All Records\n";
        cout << "Option 4: Delete Record by Account Number\n";
        cout << "Option 5: Reverse List" << endl;
        cout << "Option 6: Quit Program\n";

    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "You chose Option 1\n";    
            
            cout << "Please enter the account number of the new record:\n";
            cout << "ONLY INTEGERS 0-9 ALLOWED, NO CHARACTERS\n";
            std::cin >> accountno;
            cin.getline(garbage, 100);
           
            cout << "Please enter the name of the new record:\n";
            std::cin.getline(name, 25);

            cout << "Please enter the address of the new record:\n";
            cout << "Type $ after you are done and hit enter.\n";
            std::cin.getline(address, 80, '$');        
            cin.getline(garbage, 100);

            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
               
                cout << "Function Called:\t getaddress\n\n";
                cout << "Parameters Passed:\n";
                cout << "Address:\n\n" <<  address;
 
                cout << "Function Called:\t addRecord\n\n";
                cout << "Parameters Passed:\n";
                cout << "Account number:\t" << accountno << endl;
                cout << "Name:\t" << name << endl;
                cout << "Address:\t" << address << endl;
 
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
            cout << "You chose Option 2" << endl; 
            
            cout << "Please enter the account number of the record you want to print:" << endl;
            cin >> accountno;
            cin.getline(garbage, 100);
            
            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
 
                cout << "Function Called:\t printRecord" << endl;
                cout << "Parameters Passed:" << endl;
                cout << "Account number:\t" << accountno << endl;
              
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
 
                cout << "Function Called:\t cout" << endl;
                
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";        
 
            }
            cout << begin;
            break;

        case 4:
            cout << "You chose Option 4\n";
            cout << "Please enter the account number to be deleted:\n";
            
            cin >> accountno;
            cin.getline(garbage, 100);

            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
   
                cout << "Function Called:\t deleteRecord\n\n";
                cout << "Parameters Passed:\n";
                cout << "account number:\t" <<  accountno << endl;
 
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
            cout << "You chose Option 5" << endl;
            
            begin.reverse(); 
            break;

        case 6:
            cout << "You chose Option 6" << endl; 
 
            if (debugmode == 1)
            {
                cout << "\n";   
                cout << "***DEBUG START***\n";
                cout << "\n";       
 
                cout << "Function Called:\t none" << endl;
                cout << "Parameters Passed:\tnone" << endl;
            
                cout << "\n";  
                cout << "***DEBUG END***\n";
                cout << "\n";         
            }

            cout << "Exiting program." << endl;
            running = 0;
            break;

        default:
            cout << "Invalid choice.\n\n";   
            break;
    }
}
}
return(main_rtrn);
}
