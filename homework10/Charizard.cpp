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
//  FILE:        Charizard.cpp
//
//  DESCRIPTION:
//  Contains function definitions for class Charizard.
//  *************************************************************/

#include <iostream>
#include "Charizard.h"
using namespace std;

Charizard::Charizard()
{
    type = "orange";
    weight = 6.3;
}

Charizard::~Charizard()
{

}


void Charizard::printData()
{
    cout << "The pokemon is: Charizard" << endl;
    cout << "It is of type:\t" << type << endl;
    cout << "The weight is:\t" << weight << endl;
}
