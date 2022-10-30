/*
    Bruno DiGennaro
    CPSC 1111 001 Fall 2022
    Lab 8 - Arrays
    This program converts a decimal number input into binary using integer array
*/



#include <stdio.h>
    int main() { 
    int input;
    int array[30];
    int remainder = 0; 
    int i = 0;


        printf("Enter a decimal number: "); 
        scanf("%i", &input); 

        int num = input;

        // while loop using stored values in integer array by 2
        while (num != 0){
        remainder = num % 2; 
        array[i] = remainder; 
        num = num / 2; 
        i++;
        }

        printf("The binary equivelant of %i is ", input);

        // for loop printing the array values in the correct order
        for (i = i - 1; i >= 0; i--) {
        printf("%i",array[i]);
        }

        printf("\n");

    return 0; 
}
