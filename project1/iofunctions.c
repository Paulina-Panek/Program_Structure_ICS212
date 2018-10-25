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

/***************************************************************
//  Function name: readfile
// 
//   DESCRIPTION:   Reads struct record data from a file and stores
//                  them as an array of struct record
// 
//   Parameters:    accarray(struct record) : array of struct records
//                             
//                  filename(char) : name of the file read from
//                  
//   Return values:  0 : success
//                   1 : error opening the file
// 
//  ****************************************************************/ 

/*****
int readfile( struct record accarray[], char filename[])
{
    FILE * inf;
    int i, value, eof_check, account_temp;
   
    i = 0;
    eof_check = 0;

    inf = fopen(filename, "r");

    if (inf == NULL)
    {
        fclose(inf);
        *numcust = i;    
        value = 1;    
    }
    else
    {
        for (i = 0; (feof(inf) == 0 && eof_check == 0); i++)
        { 
            if (fscanf(inf, "%d\n", &account_temp) != 1)
            {
                eof_check = 1;
                i--;
            }
            else
            {
                accarray[i].accountno = account_temp;
                fgets(accarray[i].name, 20, inf);
                fgets(accarray[i].address, 80, inf);
            }
        }

    fclose(inf);
    *numcust = i;    
    value = 0;
    } 

return(value);

}
*****/
/***************************************************************
//  Function name: writefile
// 
//   DESCRIPTION:   Writes or updates a file with struct record data
//                  from an array
// 
//   Parameters:    accarray(struct record) : array of struct records
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
            fprintf(outf, "\n");

            ptr = ptr->next;
        }

        fclose(outf);
        value = 0;
    }

return(value);

}

