/*
program that solves a quadratic equation
ax^2 + bx + c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    // function that solves a quadratic equation

    int a,b,c;
    printf("Enter the first coefficient a: \n");
    scanf("%d", &a);
    printf("Enter the second coefficient b: \n");
    scanf("%d", &b);
    printf("Enter the third coefficient c: \n");
    scanf("%d", &c);

    double discriminant = pow(b,2) - (4*a*c);

    if (discriminant > 0){
        double sol1 = ((-1*b) + sqrt(discriminant)) / (2*a);
        double sol2 = ((-1*b) - sqrt(discriminant)) / (2*a);
        printf("Your solution are two distinct real numbers which are:\n %f and %f", sol1, sol2);
    }
    else if(discriminant == 0){
        double sol = ((-1*b) + sqrt(discriminant)) / (2*a);
        printf("Your solution is only one real number which is %f", sol);
    }
    else if(discriminant < 0){
        double real = -b/(2 * a);
        double imag = sqrt(-1 * discriminant)/(2*a);
        printf("Your solution are two distinct complex numbers which are: \n");
        printf("%f + %fi and %f - %fi\n", real, imag, real, imag);
        printf("Which is of the form a+ib, where a and b are real numbers\n");

    }


    return 0;
}
