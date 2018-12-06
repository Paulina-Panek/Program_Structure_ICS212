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
//  FILE:        Charizard.h
//
//  DESCRIPTION:
//  Header file that contains the class definition for Charizard
//
//  *************************************************************/

#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Charizard: public Pokemon
{
    public:
       Charizard();
       void printData();
       ~Charizard();
};
#endif
