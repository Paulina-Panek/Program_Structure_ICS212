#include "halfstring.h"
#include <stdio.h>

int main()
{
    int i, size_new;
    char string_old[200], string_new[101];

    printf("Enter the string you want to process:\n");
    fgets( string_old, 200, stdin);

    i = 0;

    while (string_old[i] != '\0')
    {
        i++;
    } 

    size_new = (i/2);


    string_new[size_new] ='\0';
    
    for (i = 0; i < size_new; i++)
    {
        string_new[i] = 1;

    } 

    halfstring(string_old, string_new);

    printf("Old string:\t%s\n", string_old);
    printf("New string:\t%s\n", string_new);

return(0);
}
