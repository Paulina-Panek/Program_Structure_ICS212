#include <stdio.h>

void halfstring(const char string_old[], char string_new[])
{
    int counter, i;

    printf("first old: %s\n", string_old);
    printf("first new: %s\n", string_new);

    counter = 0;

    for (i = 0; string_old[i] != '\0'; i++)
    {   
        if (i%2 == 0)
        { 
           string_new[counter] = string_old[i];
           counter++;
        } 
    }

    string_new[i + 1] = '\0';

    printf("Old string is: %s\n", string_old);
    printf("New string is: %s\n", string_new);
}
