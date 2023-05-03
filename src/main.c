#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "word_finder.h"
#include "util.h"

int main(int argc, char **argv){

    if (argc <= 2){ //filename + something
        fprintf(stderr, "Not enough arguments :( \n" );
        return 84;
    }

    int gsize = 4;
    char line[strlen(argv[2])];

    printf("argc = %d \n", argc);
    
    // reading gsize if any
    
    if (argc == 5){
        if (strcmp(argv[3], "-s") == 0){
            gsize = strtol(argv[4], NULL, 10);
        }
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
    
    //transforming line to grid
    char word[] = "noob";
    int word_size = sizeof(word) - 1;

    printf("word_size = %d \n", word_size);
    
    print_grid(gsize, &line);

    // defining found letters
    int found_letters[word_size];
    for(int i = 0; i < word_size; i++){
        found_letters[i] = 0;
    }

    for (int l = 0; l < word_size; l++){
        for(int i = 0; i < gsize; i++){
            for(int j = 0; j < gsize; j++){
                if (line[letter_position(i, j, gsize)] == word[l]){
                    found_letters[l] = 1;
                }
            }
        }
    }

    for(int i = 0; i < word_size; i++){
        if (found_letters[i] == 0){
            printf("The word %s is not in the grid\n", word);
            return 0;
            //todo make loop
        }
    }

    bool word_found = false;
    
    if (word_finder(gsize, word_size, &line, &word)){
        print_grid(gsize, &line);
    }

    return 0;
}