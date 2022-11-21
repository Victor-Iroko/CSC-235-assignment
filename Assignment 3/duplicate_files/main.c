/*
Name: Iroko victor Pamilerin
Matric No: 222476
Level: 200 lvl

This program is to remove the dupicate files from a list of files
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicates(char file_names[300][300], int num_files);

int main()
{
    FILE *input_ptr;
    input_ptr = fopen("Input_file.txt", "r"); // opens the file
    int num_test_cases; // getting the number of test cases that is in the input file
    fscanf(input_ptr ,"%d", &num_test_cases);

    for (int i=0; i<num_test_cases; i++){
        // getting the number of files in each test case
        int num_files;
        fscanf(input_ptr,"%d", &num_files);

        char files_name[num_files][300]; // where we are storing the names of the files
        int files_id[num_files]; // where we are storing the ids of the files
        char *dup; // array to store if each file contain duplicates

        for(int j=0; j<num_files; j++){
                fscanf(input_ptr, "%s %d", files_name[j], &files_id[j]); // storing the names and ids of each file in the test case
            }

        dup = duplicates(&files_name, num_files);





        for (int i=0; i<num_files; i++){

            if (dup[i] == 'U'){
                printf("%d\n", files_id[i]);
            }
            else if(dup[i] == 'D'){
                int lowest_id = files_id[i];
                for(int j=0; j<num_files; j++){
                    if (files_id[j]<files_id[i] && strcmp(files_name[i], files_name[j])==0){
                        lowest_id = files_id[j];
                    }
                }
                printf("%d\n", lowest_id);
            }
        }

        printf("\n\n");






        }




    return 0;
}

char *duplicates(char file_names[300][300], int num_files){
        char *output = malloc(num_files); // D means it has duplicates, U means it doesn't have duplicates

        for (int i=0; i< num_files; i++){
            int j;
            for (j=0; j<num_files; j++){
                if(i==j){
                    continue;
                }
                else if (strcmp(file_names[i], file_names[j]) == 0){
                    output[i] = 'D';
                    //printf("Duplicate %d %d %s %s\n", i, j, file_names[i], file_names[j]);
                    break;
                }
            }

            if (j == num_files){
                output[i] = 'U';
                //printf("Not duplicate %d %d %s %s\n", i, j, file_names[i], file_names[j]);
            }
        }

        return output;

}







