#include "halfstring.h"
#include <stdio.h>

int main()
{
    int i, /* size_old, */ size_new;
    char string_old[200], string_new[101];

    printf("Enter the string you want to process:\n");
    scanf("%s", string_old);

    i = 0;

    while (string_old[i] != '\0')
    {
        i++;
    } 
 
/* Size of the original string without null character */

/*    size_old = i; */

/* Size of the processed array without  null character */

    size_new = (i/2);

/*    string_old[size_old] = '\0'; */

    string_new[size_new] ='\0';
    
    for (i = 0; i < size_new; i++)
    {
        string_new[i] = 1;

    } 

    halfstring(string_old, string_new);

return(0);
}
