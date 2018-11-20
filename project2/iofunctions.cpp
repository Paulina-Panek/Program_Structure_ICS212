/***************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 25th, 2018
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//  Contains readfile and writefile functions. Note the functions
//  do not contain terminal I/O functions. 
//  *************************************************************/

#include "record.h"

/***************************************************************
//  Function name: readfile
// 
//   DESCRIPTION:   Reads struct record data from a file and stores
//                  them as an array of struct record
// 
//   Parameters:    start(struct record**) : pointer to the pointer
//                                       of the first struct record
//                             
//                  filename(char) : name of the file read from
//                  
//   Return values:  0 : success
//                   1 : error opening the file
// 
//  ****************************************************************/ 

int readfile(struct record ** start_ptr, char filename[])
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

            addRecord(start_ptr, accountno, name, address);

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
//   Parameters:    start(struct record) : pointer to the first struct record
//                             
//                  filename(char) : name of the file to be written
//                  
//   Return values:  0 : success
//                   1 : error opening the file
// 
//  ****************************************************************/ 

int writefile( struct record *start, char filename[] )
{
    FILE * outf;
    int value;
    struct record * ptr;

    ptr = start;
    outf = fopen(filename, "w");

    if (outf == NULL)
    {
        value = 1;
    }

    else
    {
        while (ptr != NULL)
        {
            fprintf(outf,"%d\n", ptr->accountno);
            fprintf(outf, "%s", ptr->name);
            fprintf(outf, "%s", ptr->address);
            fprintf(outf, "$\n\n\n\n");

            ptr = ptr->next;
        }
        
        fclose(outf);
        value = 0;
    }

return(value);
}

