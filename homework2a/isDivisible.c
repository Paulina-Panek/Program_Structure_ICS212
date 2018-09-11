
/***************************************************************
//  Function name: isDivisible(number, PotentialFactor)
//  //
//  //  DESCRIPTION:   Checks if <number> is divisible by
//  //                 <PotentialFactor>
//  //
//  //  Parameters:    number : looking for factors of
//  //                 PotentialFactor : checked if is a factor              
//  //
//  //  Return values: 0 : <PotentialFactor> is NOT a factor
//  //                 1 : <PotentialFactor> is a factor
//  //
****************************************************************/

#include <stdio.h>

int isDivisible(int number, int PotentialFactor)
{ 
    int result;
 
    if (number % PotentialFactor == 0)
        result = 1;
    else
        result = 0;                 

    return(result);
}
