#include <stdio.h>

void halfstring(const char string_old[], char string_new[])
{
    int counter, i;

    counter = 0;

    for (i = 0; string_old[i] != '\0'; i++)
    {   
        if (i%2 == 0)
        { 
           string_new[counter] = string_old[i];
           counter++;
        } 
    }
}
