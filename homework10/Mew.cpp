/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    Homework 10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Dec 6th, 2018
//
//  FILE:        Mew.cpp
//
//  DESCRIPTION:
//  Contains function definitions for class Mew.
//  *************************************************************/

#include <iostream>
#include "Mew.h"
using namespace std;

/*****************************************************************
//  Function name: Mew::Mew()
// 
//   DESCRIPTION:   Constructor; initializes variables for Mew
//                  
//  ****************************************************************/

Mew::Mew()
{
    type = "purple";
    weight = 2.3;
}

/*****************************************************************
//  Function name: Mew::~Mew()
// 
//   DESCRIPTION:   Destructor
//                  
//  ****************************************************************/

Mew::~Mew()
{
}

/*****************************************************************
//  Function name: Mew::printData()
// 
//   DESCRIPTION:  Prints variables for Mew
//                  
//  ****************************************************************/

void Mew::printData()
{
    cout << "The pokemon is: Mew" << endl;
    cout << "It is of type:\t" << type << endl;
    cout << "The weight is:\t" << weight << endl;
}
