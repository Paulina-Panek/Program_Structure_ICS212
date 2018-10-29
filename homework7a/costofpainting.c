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
//  FILE:        costofpainting.c
//
//  DESCRIPTION:
//  Calculates cost painting road given worker's union requirements
//
//  Parameters:  length (double) : length of the road in miles
//
//  *************************************************************/

#include <stdio.h>

int costofpainting(double length)
{
    int cost;
    
    if ((length <= 2) && (length > 0))
    {
        cost = 150*length;
    }
    else
    {
        cost = 400 + 2* costofpainting((length-2)/2);
    }

    return cost;

}
