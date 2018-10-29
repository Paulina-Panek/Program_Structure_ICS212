/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    7a
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 28th, 2018
//
//  FILE:        driver.c
//
//  DESCRIPTION:
//  Driver that calculates cost painting road given worker's union requirements
//
//  *************************************************************/

#include <stdio.h>

int costofpainting(double);

int main()
{
    double length;
    int cost;

    while(1)
    {
        printf("Enter the length of the road in miles: ");
        scanf("%lf", &length);

        cost = costofpainting(length);

        printf("The cost of painting is $%d\n", cost);
    }
  
    return 0;
}
