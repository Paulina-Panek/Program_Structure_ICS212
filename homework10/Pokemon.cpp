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
//  FILE:        Pokemon.cpp
//
//  DESCRIPTION:
//  Contains the class functions for Pokemon.
//  *************************************************************/

#include <iostream>
#include "Pokemon.h"
using namespace std;

/*****************************************************************
//  Function name: Pokemon::Pokemon()
// 
//   DESCRIPTION:   Constructor
//                  
//  ****************************************************************/

Pokemon::Pokemon()
{
    type = "colored";
    weight = 100.5;
}

/*****************************************************************
//  Function name: Pokemon::~Pokemon()
// 
//   DESCRIPTION:   Destructor (virtual for the base class)
//                  
//  ****************************************************************/

Pokemon::~Pokemon()
{
}


