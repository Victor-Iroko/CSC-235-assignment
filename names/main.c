/*
Program that accepts the names of 10 students and prints it out
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

    // Accepting the names of 10 students
    char names[10][100]; // two dimensional array that stores arrays

    for (int i = 0; i<=9; i++){
        printf("Enter your name here: \n");
        gets(names[i]);
    }

    // printing out the names
    printf("\nThe names entered are: \n");
    for (int i=0; i<=9; i++){
        printf("%s\n", names[i]);
    }

    return 0;
}
