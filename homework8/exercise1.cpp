/*****************************************************************
//   NAME:        Paulina Panek
// 
//   HOMEWORK:    8
// 
//   CLASS:       ICS 212
// 
//   INSTRUCTOR:  Ravi Narayan
// 
//   DATE:        Nov 7th, 2018
// 
//   FILE:        exercise1.cpp
// 
//   DESCRIPTION:
//    A simple program listing factors of an integer given
//    by user interface written in C++
//  *************************************************************/

#include <iostream>
using namespace std;
#include <stdlib.h>

int getInt();
void isDivisible(int, int, bool &);

int main()
/***************************************************************
//  Function name: main()
//  //
//  //  DESCRIPTION:   Generates an indexed table
//  //                 of factors of a positive integer
//  //
//  //  Parameters:    none
//  //
//  //  Return values: always 0
//  //                
****************************************************************/
{  
    int user_int, i, index;
    bool factor;
    bool& check = factor;

    cout << "This program calulates the factors of an integer provided by the user.\n";

    user_int = getInt();
    cout << "You entered:\n" << user_int;

    index = 1;

    cout << "%10s%10s\n" <<  "Index" << "Factor";

    for (i = 1; i <= user_int; i++)
    {             
        isDivisible(user_int, i, check);
        factor = check;
                
        if (factor == true)
        {
            cout << "%10d%10d\n" <<  index << i;
            index++;
        }
    }

    return(0);
}

int getInt()
/***************************************************************
//  Function name: getInt()
//  //
//  //  DESCRIPTION:   Userinterface function that requests user
//  //                 to provide input and checks if it is a 
//  //                 positive integer
//  //
//  //  Parameters:    none
//  //                               
//  //  Return values: user_int : positive integer               
//  //
****************************************************************/
 
{
    char input[12];
    int user_int;

    cout << "Please enter an integer greater than 0:\n";
    cin >> input;

    /* Loops below ensure correct error message is displayed even
    // if incorrect input is provided multiple times in a row */

    while (input[0] == '0')
    {
        cout << "You entered 0. Please enter a POSITIVE integer.\n";
        cin >> input;
    }

    user_int = atoi(input);

    /* atoi returns 0 if characters were entered
    // Previous loop ensured that user didn't enter 0
    // Thus, if user_int = 0 characters were entered
    // If integer entered, atoi returns integer (+ or -) */

    while (user_int <= 0)
    { 
        if  (user_int == 0)
        {
             cout << "You entered character(s). Please enter an integer.\n";
        }
  
        else if (user_int <= 0)
        {  
            cout << "Please enter a POSITIVE integer to check its factors:\n";   
        }
     
        cin >> input;
   
    /* Once user enters new input, below loop will first evaluate if it was 0
    // Then, again use atoi and go through the big loop to ensure new input 
    // not a character */
 
        while (input[0] == '0')
        {
            cout << "You entered 0. Please enter a POSITIVE integer.\n";
            cin >> input;
        }

        user_int = atoi(input);
    }

return(user_int);  
}

void isDivisible(int number, int PotentialFactor, bool& check)
/***************************************************************
//  Function name: isDivisible(number, PotentialFactor)
//  //
//  //  DESCRIPTION:   Checks if <number> is divisible by
//  //                 <PotentialFactor>
//  //
//  //  Parameters:    number : looking for factors of
//  //                 PotentialFactor : checked if is a factor              
//  //
****************************************************************/

{ 
    check = (number % PotentialFactor == 0);
} 
