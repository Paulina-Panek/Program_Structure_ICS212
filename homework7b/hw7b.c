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
    unsigned char data1[4000], data2[4000], data3[4000];
    int size;

    size = sizeof(data1[0]);
 
    printf("*** image1***BEFORE************\n");
    readfile(data1, &size, "image1.gif");
    printinfor(data1);
    changecolor(data1);
    printf("*** image1***AFTER************\n");
    printinfor(data1);
    writefile(data1, size, "result1.gif");

    printf("*** image2***BEFORE***********\n");
    readfile(data2, &size, "image2.gif");
    printinfor(data2);
    changecolor(data2);
    printf("*** image2***AFTER************\n");
    printinfor(data2);
    writefile(data2, size, "result2.gif");

    printf("*** image3***BEFORE***********\n"); 
    readfile(data3, &size, "image3.gif");
    printinfor(data3);
    changecolor(data3);
    printf("*** image3***AFTER************\n");
    printinfor(data3);
    writefile(data3, size, "result3.gif");

    return(0);
}
