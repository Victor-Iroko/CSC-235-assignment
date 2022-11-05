/*
Program to count from 1 to n
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    printf("\n"); // keeps a space between the input and the numbers printed

    // loop that prints 1 to n
    for(int i = 1; i <= n; i++){
            printf("%d\n", i);

    }

    return 0;
}
