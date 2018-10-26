/***************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 6th, 2018
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//  Contains readfile and writefile functions. Note the functions
//  do not contain terminal I/O functions. 
//  *************************************************************/

#include "record.h"

extern int debugmode;

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
    int account_temp, accountno, eof_check, size, val;
    
    FILE *inf = fopen(filename, "r");
                
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

            if (debugmode == 1)
            { 
            printf("***DEBUG (inside readfile) START***\n");
            printf("\n"); 
            printf("Function Called:\t addRecord\n\n");
            printf("Parameters Passed:\n");
            printf("Address of start pointer:\t%p\n", (void*)start_ptr);
            printf("Account number:\t%d\n", accountno);
            printf("Name:\t%s", name);
            printf("Address:\n");
            printf("%s\n\n", address);
            printf("***DEBUG (inside readfile) END***\n");
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
    outf = fopen(filename, "w+");

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
            fprintf(outf, "$\n");

            ptr = ptr->next;
        }
        
        fclose(outf);
        value = 0;
    }

return(value);

}

