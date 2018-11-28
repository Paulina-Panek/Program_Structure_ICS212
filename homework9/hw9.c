/*****************************************************************
//  //  NAME:        Paulina Panek
//  //
//  //  HOMEWORK:    9
//  //
//  //  CLASS:       ICS 212
//  //
//  //  INSTRUCTOR:  Ravi Narayan
//  //
//  //  DATE:        November 28th, 2018
//  //
//  //  FILE:        isDivisible.c
//  //
//  //  DESCRIPTION:
//  //   A simple program listing factors of an integer given
//  //   by user interface
//  *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hw9.h"
#include <jni.h>

//int isDivisible(int, int);

JNIEXPORT jint JNICALL Java_hw9_isDivisible(JNIEnv *env, jobject obj, jint number, jint PotentialFactor)
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

{ 
    jint result;
 
    if (number % PotentialFactor == 0)
        result = 1;
    else
        result = 0;                 

    return(result);
} 
