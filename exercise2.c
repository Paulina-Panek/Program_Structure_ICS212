/*****************************************************************
//  //  //  NAME:        Paulina Panek
//  //
//  //  //  HOMEWORK:    1
//  //  //
//  //  //  CLASS:       ICS 212
//  //  //
//  //  //  INSTRUCTOR:  Ravi Narayan
//  //  //
//  //  //  DATE:        September 6th, 2018
//  //  //
//  //  //  FILE:        exercise2.c
//  //  //
//  //  //  DESCRIPTION:
//  //  //  Exercise on what happens in the memory
//  //  //  Getting addresses
//  //  //
//  //  *************************************************************/


#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int i, num1, num2 = 13;
    char c = 'H';
    float score1 = 12.5;
    char ca[3] = "Hi";

    printf("num1\t address hex:\t%p  address_dec:\t%ld value:\t%d\n", &num1, (long)(&num1), num1 );
    printf("num2\t address hex:\t%p  address_dec:\t%ld value:\t%d\n", &num2, (long)(&num2), num2 );
    printf("c\t address hex:\t%p  address_dec:\t%ld value:\t%c\n", &c, (long)(&c), c );
    printf("score1\t address hex:\t%p  address_dec:\t%ld value:\t%f\n", &score1, (long)(&score1), score1 );
    printf("ca0 \taddress hex:\t%p  address_dec:\t%ld value:\t%c\n", &ca[0], (long)(&ca[0]), ca[0] );
    printf("ca1 \taddress hex:\t%p  address_dec:\t%ld value:\t%c\n", &ca[1], (long)(&ca[1]), ca[1] );
    printf("ca2 \taddress hex:\t%p  address_dec:\t%ld value:\t%c\n", &ca[2], (long)(&ca[2]), ca[2] ); 
    printf("argc \taddress hex:\t%p  address_dec:\t%ld value:\t%d\n", &argc, (long)(&argc), argc );
    printf("argv[0] \taddress hex:\t%p  address_dec:\t%ld value:\t%c\n", &argv[0], (long)(&argv[0]), argv[0] );
    printf("argv\t address hex:\t%p  address_dec:\t%ld value:\t%c\n", &argv, (long)(&argv), argv);      
    printf("argv[0]\t%p\n", argv[0]);
   
    printf("\nWhen using sizeof function:\n\n");
    
    i = sizeof(score1);
    printf("%d\n", i);


    dummy(num2, c, ca, score1);

    /* pause here */


    return 0;
}

void dummy(int x, char y, char * z, float w)
{   int i;

    printf("x\t address hex:\t%p  address_dec:\t%ld value:\t%d\n", &x, (long)(&x), x );
    printf("y\t address hex:\t%p  address_dec:\t%ld value:\t%c\n", &y, (long)(&y), y );
    printf("w\t address hex:\t%p  address_dec:\t%ld value:\t%f\n", &w, (long)(&w), w );
    printf("z\t address hex:\t%p  address_dec:\t%ld value:\t%p\n", &z, (long)(&z), z );
 

    x++;
    y++;
    w = w + 2.3;

    printf("After function update\n\n");

    printf("x\t address hex:\t%p  address_dec:\t%ld value:\t%d\n", &x, (long)(&x), x );
    printf("y\t address hex:\t%p  address_dec:\t%ld value:\t%c\n", &y, (long)(&y), y );
    printf("w\t address hex:\t%p  address_dec:\t%ld value:\t%f\n", &w, (long)(&w), w );
    printf("z\t address hex:\t%p  address_dec:\t%ld value:\t%p\n", &z, (long)(&z), z );
    
    printf("\nWhen using sizeof function:\n\n");
    i = sizeof(w);
    printf("%d\n", i);


}
