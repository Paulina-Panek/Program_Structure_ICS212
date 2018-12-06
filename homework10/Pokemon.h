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
//  FILE:        Pokemon.h
//
//  DESCRIPTION:
//  Header file that contains the class definition for Pokemon
//
//  *************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include "Pokemon.h"
using namespace std;



class Pokemon
{
    protected:
        string type;
        float weight;
    public:
        virtual void printData() = 0;
        Pokemon();
        ~Pokemon();
        

};

#endif
