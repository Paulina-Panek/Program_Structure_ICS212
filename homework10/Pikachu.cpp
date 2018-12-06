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
//  FILE:        Pikachu.cpp
//
//  DESCRIPTION:
//  Contains function definitions for class Pikachu.
//  *************************************************************/

#include <iostream>
#include "Pikachu.h"
using namespace std;

/*****************************************************************
//  Function name: Pikachu::Pikachu()
// 
//   DESCRIPTION:   Constructor, initializes variables for Pikachu
//                  
//  ****************************************************************/

Pikachu::Pikachu()
{
    type = "yellow";
    weight = 5.1;
}

/*****************************************************************
//  Function name: Pikachu::~Pikachu()
// 
//   DESCRIPTION:   Destructor
//                  
//  ****************************************************************/

Pikachu::~Pikachu()
{
}

/*****************************************************************
//  Function name: Pikachu::printData()
// 
//   DESCRIPTION:  Prints Pikachu variables
//                  
//  ****************************************************************/

void Pikachu::printData()
{
    cout << "The pokemon is: Pikachu" << endl;
    cout << "It is of type:\t" << type << endl;
    cout << "The weight is:\t" << weight << endl;
}
