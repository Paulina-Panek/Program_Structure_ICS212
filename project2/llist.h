/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 25th, 2018
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//  Header file that contains the class definition
//  *************************************************************/

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "record.h"

using namespace std;

class llist
{
  private:
    record *    start;
    char        filename[16];
    int         readfile();
    void        writefile();
    record *    reverse(record * );
    void        cleanup();

  public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord (int, char [ ],char [ ]);
    int printRecord (int);
    int deleteRecord(int);
    void reverse();

    friend ostream & operator << (ostream&, const llist&);
};

#endif
