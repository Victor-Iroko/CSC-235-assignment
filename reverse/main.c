/*
Program that reverses a string
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char sentence[256];
    printf("Enter your sentence: \n");
    fgets(sentence, 256, stdin);
    //printf("\n");

    // function reverses a sentence
    int n = strlen(sentence); // length of the string

    char reversedSentence[n]; // variable that would hold the reversed sentence

    for (int i=n-1; i>=0; i--){
        reversedSentence[i] = sentence[n-i-1];
        /*
        v = 0
        i = 1
        c = 2
        t = 3
        o = 4
        r = 5
        */
    }

    printf("%s", reversedSentence);

    return 0;
}
