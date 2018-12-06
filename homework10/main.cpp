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
//  FILE:        main.cpp
//
//  DESCRIPTION:
//  Main function that uses class hierarchy
//  *************************************************************/

#include <iostream>
#include "Pokemon.h"
#include "Pikachu.h"
#include "Mew.h"
#include "Charizard.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

void checkPokedex(Pokemon *);

int main()
{
    vector<Pokemon*> pokemonVector;
    std::map<std::string, Pokemon*> pokemonMap;
    vector<Pokemon*>::iterator iter;

    Pokemon* poke1 = new Pikachu;
    Pokemon* poke2 = new Pikachu;
    Pokemon* poke3 = new Mew;
    Pokemon* poke4 = new Mew;
    Pokemon* poke5 = new Charizard;
    Pokemon* poke6 = new Charizard;

    pokemonVector.push_back(poke1);
    pokemonVector.push_back(poke3);
    pokemonVector.push_back(poke5);

    pokemonMap["Pikachu"] = poke2;
    pokemonMap["Mew"] = poke4;
    pokemonMap["Charizard"] = poke6;

    cout << endl;
    cout << "----- Pokemons in pokemonVector: ------" << endl;

    for (iter = pokemonVector.begin(); iter != pokemonVector.end(); ++iter)
    {
        checkPokedex(*iter);
        cout << endl;
    }

    cout << "----- Pokemons in pokemonMap: -----" << endl;
 
    checkPokedex(pokemonMap["Pikachu"]);
    cout << endl;
    checkPokedex(pokemonMap["Mew"]); 
    cout << endl;
    checkPokedex(pokemonMap["Charizard"]); 
    cout << endl;

    return(0);
}



void checkPokedex(Pokemon *pokemon)
{
    pokemon->printData();
}
