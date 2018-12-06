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
//  FILE:        Mew.h
//
//  DESCRIPTION:
//  Header file that contains the class definition for Mew
//
//  *************************************************************/

#ifndef MEW_H
#define MEW_H

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Mew: public Pokemon
{
    public:
        Mew();
        ~Mew();
        void printData();
};
#endif
