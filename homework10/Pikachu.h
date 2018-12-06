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
//  FILE:        Pikachu.h
//
//  DESCRIPTION:
//  Header file that contains the class definition for Pikachu
//
//  *************************************************************/

#ifndef PIKACHU_H
#define PIKACHU_H

#include <iostream>
#include "Pokemon.h"
using namespace std;

class Pikachu: public Pokemon
{
    public:
        Pikachu();
        ~Pikachu();
        void printData();
};
#endif
