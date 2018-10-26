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

int readfile(struct record ** pstart, char filename[])
{

	char name[25], address[80], buffer;
	int account_temp, accountno, eof_check, size;
	FILE *inf = fopen(filename, "r");

  eof_check = 0;

	if(inf == NULL)
	{
		return 0;
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
		addRecord(pstart, accountno, name, address);
            }
        }

	fclose(inf);

	return 1;
}

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
            fprintf(outf, "$\n");

            ptr = ptr->next;
        }
        
        fclose(outf);
        value = 0;
    }

return(value);

}

