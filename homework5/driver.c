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

#include <stdio.h>
#include "record.h"
#include "prototypes.h"
#include <string.h>

int main(int argc, char* argv[])
{

struct record bankone[5];
int numcustomers;
char filename[15];

strcpy(filename, argv[1]);

printf("File tested:\t%s\n", filename);

/*****************************************************
// Hardcoded array of struct records for tests START
// **************************************************/

bankone[0].accountno = 101010;
strcpy(bankone[0].name, "Paulina Panek\n");
strcpy(bankone[0].address, "Bilger Hall 203\n");

bankone[1].accountno = 101013;
strcpy(bankone[1].name, "Karolina Panek\n");
strcpy(bankone[1].address, "Belchatow, Poland\n");

bankone[2].accountno = 101015;
strcpy(bankone[2].name, "Kotel Panek\n");
strcpy(bankone[2].address, "Wies pod lasem, Poland\n");

bankone[3].accountno = 101019;
strcpy(bankone[3].name, "Patrycja Kotela\n");
strcpy(bankone[3].address, "Kawalerka, Warszawa\n");

bankone[4].accountno = 101050;
strcpy(bankone[4].name, "Sergio Informatyk\n");
strcpy(bankone[4].address, "San Francisco, California\n");

/*****************************************************
// Hardcoded array of struct records for tests END
// **************************************************/

/*numcustomers = sizeof(bankone);*/
/*writefile(bankone , &numcustomers, filename);*/


/*printf("%d\n", numcustomers);*/
return(0);
}
