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
//  Main function that uses class hierarchy, map, and vector
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

/*****************************************************************
//  Function name: main
// 
//   PARAMETERS:   none
//
//   RETURN VALUE: 0 success
//                 1 fail
//                  
//  ****************************************************************/

int main()
{
    int rtrn_val;
    vector<Pokemon*> pokemonVector;
    std::map<std::string, Pokemon*> pokemonMap;
    vector<Pokemon*>::iterator iter;

    rtrn_val = 1;
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

    delete(poke1);
    delete(poke2);
    delete(poke3);
    delete(poke4);
    delete(poke5);
    delete(poke6);
    rtrn_val = 0;
    return(rtrn_val);
}

/*****************************************************************
//  Function name: checkPokedex(Pokemon *)
// 
//   PARAMETERS:   Pokemon *pokemon : pointer to the pokemon
//                  
//  ****************************************************************/

void checkPokedex(Pokemon *pokemon)
{
    pokemon->printData();
}
