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

Pikachu::Pikachu()
{
    type = "yellow";
    weight = 5.1;
}

Pikachu::~Pikachu()
{

}

void Pikachu::printData()
{
    cout << "The pokemon is: Pikachu" << endl;
    cout << "It is of type:\t" << type << endl;
    cout << "The weight is:\t" << weight << endl;
}
