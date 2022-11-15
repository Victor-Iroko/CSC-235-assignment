/*
Name: Iroko victor Pamilerin
Matric No: 222476
Last edited: 14th Nov 2022 9:56AM
Level: 200 level
Assignment 2; Adam walking

This code is to read from a file, the number of times Adam walked (characterized by the number of Us we see before a D) for each try.

Algorithm
---------
1. Read the first line of the file, which indicates the number of tries we'll be reading and store it somewhere
2. For each try we'll be reading, we'll then output the number of times Adam walked before falling and store the result in an array
3. After that, we'll then print the result out to the console and/or write it into another file (Adam_out.txt)

Adam_in.txt is the file where we'll be reading the number of tries and each try that adam did
Adam_out.txt is the file where we'll be writing output to
*/


#include <stdio.h>
#include <stdlib.h>

int single_try(char walk[100]); // function prototyping


int main()
{
    // opening the input file, reading and storing the number of tries Adam made
    FILE *read_pointer;
    read_pointer = fopen("Adam_in.txt", "r");
    int num_tries = 0; // I set it to zero, incase the file is empty it will won't print out anything, since this is the variable used in the loops
    fscanf(read_pointer, "%d", &num_tries);


    // creating variables to store the tries and the number of steps Adam made before falling
    char tries[num_tries][100];
    int steps[num_tries];


    // reads each try Adam made and stores the number of steps he made into the variable step
    for (int i = 0; i < num_tries; i++){
        fscanf(read_pointer, "%s", tries[i]);
        steps[i] = single_try(tries[i]); // single try is a function that takes in a try Adam made and outputs the number of steps he made
    }

    fclose(read_pointer); // closes the file


    // prints out the result (number of steps for each try) out to the console and also write it to Adam_out
    FILE *write_pointer = fopen("Adam_out.txt", "w");
    for (int i = 0; i < sizeof(steps) / sizeof(steps[0]); i++){
        fprintf(write_pointer,"%d\n", steps[i]);
        printf("%d\n", steps[i]);
    }


    fclose(write_pointer); // closes Adam_out



    return 0;
}


int single_try(char try[100]){
    /*

    function that takes in a single try and returns the number of steps he made before falling

    Paramter
    --------
    try: This is the string of UUUUUDDDDUUU upto 100 characters (just one case)

    */

    int n = strlen(try); // getting the length of the try i.e. the overall number of steps he made for that try
    //checking to see if the number of characters is more than 100
    if (n > 100){
        printf("The characters is more than 100");
        return 0;
    }

    for (int i=0; i<n; i++){
        char step = try[i];


        if (step == 'U'){
                if ((i+1) == n){
                    // special case if the entire string is just Us e.g. UUUUUUUUU
                    return i + 1;
                }
          continue;
        }
        else if (step == 'D') {
            return i;
        }
        else {
            printf("This character %c doesn't belong here\n", step); // any other character apart from UD
            return i;
        }


    }


}
