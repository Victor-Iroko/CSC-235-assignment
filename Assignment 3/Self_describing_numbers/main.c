#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_num_digits(int num);
int *counter(char num[300], int num_digits);

int main()
{

    FILE *input_pointer;
    input_pointer = fopen("Input_file.txt", "r");

    int num_test_cases;
    fscanf(input_pointer, "%d", &num_test_cases);

    for (int i=0; i<num_test_cases; i++){
        int number;
        fscanf(input_pointer, "%d", &number);
        int num_digits = get_num_digits(number);
        char number_str[num_digits];
        sprintf(number_str, "%d", number);


        int *digits_count = counter(&number_str, num_digits);


        for (int i=0; i<num_digits; i++){

            if (number_str[i] == (digits_count[i]+'0')){
                if (i+1 == num_digits){
                    printf("Self describing\n");
                }
                continue;
            }
            else {
                printf("Not self describing\n");
                break;
            }

        }








}

return 0;
}


int get_num_digits(int num){
        int num_digits = 0;
        while (num>0){
            num = num / 10;
            num_digits++;
        }

        return num_digits;

}

int *counter(char num[300], int num_digits){
    int *digits = malloc(9);

    for (int i=0; i<=9; i++){
        int count = 0;
        for (int j=0; j<num_digits; j++){
            if ((i+'0') == num[j]){

                count ++;
                }
        }
        digits[i] = count;



    }
    return digits;
}
