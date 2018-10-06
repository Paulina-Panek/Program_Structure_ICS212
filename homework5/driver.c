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
//  FILE:        driver.c
//
//  DESCRIPTION:
//  Tests writefile and readfile functions.
//  
//  *************************************************************/

#include <stdio.h>
#include "record.h"
#include "prototypes.h"
#include <string.h>

/***************************************************************
//  Function name:  main
// 
//   DESCRIPTION:   Provides initial struct record data for writefile. Passes
//                  parameters to readfile. Prints tests information on stdout.            
//
//   Parameters:    argc(int) : number of parameters user used when starting
//                              the program
//                          
//                  argv(char*) : argv[1] is the file to be written
//                                argv[2] is the file to be read
//                                   
//   Return value:  Always 0
//  ****************************************************************/ 

int main(int argc, char* argv[])
{

struct record bankone[5];
int numcustomers;
char filename[15], filename2[15];

strcpy(filename, argv[1]);
strcpy(filename2, argv[2]);

printf("File to be written:\t%s\n", filename);

/*****************************************************
// Hardcoded array of struct records for tests START
// **************************************************/

bankone[0].accountno = 101010;
strcpy(bankone[0].name, "Paulina Panek\n");
strcpy(bankone[0].address, "Bilger Hall 203\n");

bankone[1].accountno = 101013;
strcpy(bankone[1].name, "Dilan and Stefan\n");
strcpy(bankone[1].address, "1111 Pretty Str, Vancouver, Canada\n");

bankone[2].accountno = 101015;
strcpy(bankone[2].name, "Kotel Panek\n");
strcpy(bankone[2].address, "Wies pod lasem, Poland\n");

bankone[3].accountno = 101019;
strcpy(bankone[3].name, "Patrycja Kotela\n");
strcpy(bankone[3].address, "001 Kawalerka, Warszawa\n");

bankone[4].accountno = 101050;
strcpy(bankone[4].name, "Sergio Informatyk\n");
strcpy(bankone[4].address, "San Francisco, California\n");

/*****************************************************
// Hardcoded array of struct records for tests END
// **************************************************/

numcustomers = (sizeof(bankone))/(sizeof(bankone[0]));

printf("Number of customers before calling any function:\t%d\n\n", numcustomers);

printf("TEST 1: WRITING HARDCODED RECORDS TO FILE:\n\n");
writefile(bankone, numcustomers, filename);
printf("File the function writefile written to:\t%s\n", filename);
printf("Number of customers:\t%d\n\n", numcustomers);

printf("TEST 2: READING FROM FILE GENERATED IN TEST 1:\n\n");
readfile(bankone, &numcustomers, filename);
printf("File the function readfile read from:\t%s\n", filename);
printf("Number of customers:\t%d\n\n", numcustomers);

printf("TEST 3: WRITING THE DATA READ IN TEST 2 TO output_test3.txt\n");
printf("Output file of TEST1 and output file of TEST3 should be the same\n\n");
writefile(bankone, numcustomers, "output_test3.txt");
printf("File the function writefile written to:\t%s\n", "output_test3.txt");
printf("Number of customers:\t%d\n\n", numcustomers);

printf("TEST 4: READING FROM A SAMPLE FILE\n");
printf("Uses the second file specified by the user when calling driver\n\n");
readfile(bankone, &numcustomers, filename2);
printf("File the function readfile read from:\t%s\n", filename2);
printf("Number of customers:\t%d\n\n", numcustomers);

printf("TEST 5: WRITING THE DATA READ IN TEST 4 TO output_test5.txt\n");
printf("The sample file used in TEST4 should be the same as output_test5.txt\n\n");
writefile(bankone, numcustomers, "output_test5.txt");
printf("File the function writefile written to:\t%s\n", "output_test5.txt");
printf("Number of customers:\t%d\n\n", numcustomers);

return(0);

}
