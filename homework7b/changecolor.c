 /****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    7b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5th, 2018
//
//  FILE:        changecolor.c
//
//  DESCRIPTION:
//  Flips colors of .gif according to specified rules
//  *************************************************************/

void changecolor(unsigned char data1[])
{
    int check, i;

    check = 64;

    for (i = 13; i < 25; i = i + 3)
    {
        if (((data1[i] & check) == check) && ((data1[i + 1] & check) == check) && ((data1[i + 2] & check) == check))
        {
            data1[i] = data1[i] >> 2;
            data1[i + 1] = data1[i + 1] >> 2;
            data1[i + 2] = data1[i + 2] >> 2;
        }
        else
        {
            data1[i] = data1[i] | 12;
            data1[i + 1] = data1[i + 1] ^ 160;
            data1[i + 2] = data1[i + 2] & 175;
        }  
    }
}
