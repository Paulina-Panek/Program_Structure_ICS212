/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    7b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5th, 2018
//
//  FILE:        hw7b.c
//
//  DESCRIPTION:
//  Main function that reads a gif, converts colors, and writes it 
//  to a new file
//  *************************************************************/

#include "header.h"

int main()
{
    unsigned char data[4000];
    int size;

    size = sizeof(data[0]);

    readfile(data, &size, "image1.gif");

    printinfor(data);

    writefile(data, size, "result1.gif");

    return(0);
}
