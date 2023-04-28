#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
// #include "commandline_reader_functions.h"

int main(int argc, char **argv){

    if (argc <= 2){ //filename + something
        fprintf(stderr, "Not enough arguments :( \n" );
        return 84;
    }


    int gsize = 4;
    char line[strlen(argv[2])];
    for (int i = 0; i < argc; i++){
        printf("%s (i = %d)", argv[i], i);
    }
    printf("\n");
    
    //commit

    printf("argc = %d \n", argc);
    
    // reading gsize if any
    
    if (argc == 5){
        if (strcmp(argv[3], "-s") == 0){
            gsize = strtol(argv[4], NULL, 10);
        }
        // printf("%s", argv[3]);
    }

    

    if (strcmp(argv[1],"-g") == 0){
        if (strlen(argv[2]) != gsize * gsize){
            fprintf(stderr, "Incorrect word or grid-size (now gridsize = %d) \n", gsize);
            return 84;
        }
        else {
            strcpy(line, argv[2]);
        }
    }
    else {
        fprintf(stderr, "Incorrect command \n");
        return 84;
    }

    printf("%s \n", line);
    
    //transforming line to grid
    
    char word[] = "noob";
    int word_size = sizeof(word) - 1;
    char grid[4][4];
    int temp = 0;
    for(int i = 0; i < gsize; i++){
        for(int j = 0; j < gsize; j++){
            grid[i][j] = line[temp];
            temp++;
        }
    }
    
    //printing grid
    for(int i = 0; i < gsize; i++){
        if (i == 0){
            for (int k = 0; k < gsize * 2 + 3; k++){
                printf("+");
            }
            printf("\n");
        }
        for(int j = 0; j < gsize; j++){
            if (j == 0){
                printf("| ");
            }
            printf("%c ", grid[i][j]);
            if (j == gsize - 1){
                printf("|");
            }
        }
        printf("\n");
        if (i == gsize - 1){
            for (int k = 0; k < gsize * 2 + 3; k++){
                printf("+");
            }
            printf("\n");
        }
    }

    // defining found letters
    bool found_letters[word_size];
    for(int i = 0; i < word_size; i++){
        found_letters[i] = false;
    }

    for (int l = 0; l < word_size; l++){
        for(int i = 0; i < gsize; i++){
            for(int j = 0; j < gsize; j++){
                if (grid[i][j] == word[l]){
                    found_letters[l] = true;
                }
            }
        }
    }

    for(int i = 0; i < word_size; i++){
        if (found_letters[i] == 0){
            printf("The word %s is not in the grid\n", word);
        }
    }

    int grid_int[4][4];

    return 0;
}