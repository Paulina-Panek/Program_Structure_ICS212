/****************************************************************
//  NAME:        Paulina Panek
//
//  HOMEWORK:    9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27th, 2018
//
//  FILE:        hw9.java
//
//  DESCRIPTION:
//  Java user interface that obtains an integer from user and
//  returns a formatted table with divisors of that integer 
*****************************************************************/

import java.util.Scanner;

public class hw9
{
    static
    {
        System.loadLibrary("hw9");
    }

    public static native int isDivisible(int input, int PotentialFactor);

    public static void main(String[] args)
    {
        int input, index, factor, i;

        Scanner scanner = new Scanner(System.in);

        System.out.print("This program calulates the factors of an integer provided by the user.\n");
        System.out.print("Please enter an integer greater than 0:\n");

        if (scanner.hasNextInt())
        {
            input = scanner.nextInt();
        
            if (input <= 0)
            {
                System.out.print("Incorrect input format. Make sure you enter an integer larger than 0.\n");
            }
            else
            {                    
                System.out.printf("You entered:\t" + input +"\n");
                index = 1;
                System.out.print("Index\tFactor\n");

                for (i = 1; i<= input; i++)
                {
                    factor = isDivisible(input, i);
        
                    if (factor == 1)
                    {
                        System.out.println(String.format("%5d\t%6d", index, i));
                        index++;
                    }  
                }
            }
        }
        else
        {
            System.out.print("Incorrect input format. Make sure you enter an integer larger than 0.\n");
        } 

    }
}
