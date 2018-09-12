#include <stdio.h>
#include <string.h>


int main ()
{
    char first[20], last[20],  username[6], ifshort[6];
    int length, howShort;

    printf("Please enter your first name:\n");
    scanf("%s", first);

    printf("Please enter your last name:\n");
    scanf("%s", last);

/* Generating username consisting of 6 characters */

    /* 1. STRCAT: Combine last with first */

    strcat(last, first);
    
    /* 2. STRLEN: Check lenght of appended string */

    length = strlen(last); 

    /* 3. STRCPY 4. STRNCAT If shorter than 6 characters, add 0s at the end.
       5. STRNCPY If longer than 6, take only the first 6 */

    if (length < 6)
    {
        strcpy(ifshort, "000000");
        howShort = 6 - length;
        strncat(last, ifshort, howShort);
    }

        strncpy(username, last, 6);


    printf("Your username is:\t%s\n", username);

 
return(0);
}
