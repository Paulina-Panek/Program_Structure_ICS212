#ifndef RECORD
#define RECORD
typedef struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
} record;

#endif

int addRecord (struct record**, int, char [], char []);

int printRecord (struct record*, int);

void printAllRecords (struct record*);

int deleteRecord (struct record**, int );

void getaddress (char[], int);

