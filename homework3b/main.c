#/*************************************************************
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

int debug, result;
char keyword[5];

int  main(int argc, char *argv[])
{
    if (argc > 1)
    {
        strcpy(keyword, "debug");
        result = strcmp(argv[1], keyword);
        
        if ((argc < 3) && (result == 0))
        {
             debug = 1;
             printf("debug = 1\n");
        }

        else 
            {
                printf("Wrong program call.\n");
            }   
    }
    else
    {
         debug = 0;
         printf("debug = 0\n");
    }

return(0);
}


