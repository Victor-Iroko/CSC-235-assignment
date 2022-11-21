#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_pointer = fopen("Input_file.txt", "r"); // open the file

    // read the number of test cases
    int num_test_cases;
    fscanf(input_pointer, "%d", &num_test_cases);

    for (int i=0; i<num_test_cases; i++){
        // for each test case, first read the number of files
        int num_files;
        fscanf(input_pointer, "%d", &num_files);

        // variables to store the file names and indexes for the test case
        char file_names[num_files][300];
        int file_index[num_files];

        // store the file names and indexes in the corresponding variables
        for (int j=0; j<num_files; j++){
            fscanf(input_pointer, "%s %d", file_names[j], &file_index[j]);
        }


        // an array to store the result i.e. the lowest for each file
        int result[num_files];
        // looping through each file name
        for (int k=0; k<num_files; k++){
            int lowest_index = file_index[k]; // setting the initial index to current  file index

            // another loop through each file again
            for (int m=0; m<num_files; m++){

                // we test if the files are equal and if the index of the inner file loop is lower than the index of the outer file loop
                if ((strcmp(file_names[k], file_names[m]) == 0) && (file_index[m] < file_index[k])){
                        lowest_index = file_index[m]; // if the condition is fufilled set the lowest index for that file to the current inner loop index
                }
            }

            // store the lowest index for the file
            result[k] = lowest_index;

        }

        // print the lowest index for each file
        for (int n=0; n<num_files; n++){
            printf("%d\n", result[n]);
        }

        // to seperate test cases
        printf("\n\n");

    }


    return 0;
}
