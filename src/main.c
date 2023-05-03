#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "word_finder.h"
#include "util.h"

int main(int argc, char **argv){
    /*
        array-check, which args are found
        0: filename
        1: -g
        2: grid
        3: -s
        4: size
        5: -w
        6: word

        when found, position are written
    */
    int cmd_args[7] = {-1, -1, -1, -1, -1, -1, -1};

    if (argc <= 2){ //filename + something
        fprintf(stderr, "Not enough arguments :( \n" );
        return 84;
    }

    for (int i = 0; i < argc; i++){
        if (!strcmp(argv[i], "-g")){
            if (i+1 < argc && !isspace(*argv[i+1])){
                cmd_args[1] = i;
                cmd_args[2] = i + 1;
            }
            else {
                fprintf(stderr, "Incorrect command \n");
                return 84;
            }
        }

        if (!strcmp(argv[i], "-s")){
            if (i+1 < argc && !isspace(*argv[i+1])){
                cmd_args[3] = i;
                cmd_args[4] = i + 1;
            }
            else {
                fprintf(stderr, "Incorrect command \n");
                return 84;
            }
        }

        if (!strcmp(argv[i], "-w")){
            if (i+1 < argc && !isspace(*argv[i+1])){
                cmd_args[5] = i;
                cmd_args[6] = i + 1;
            }
            else {
                fprintf(stderr, "Incorrect command \n");
                return 84;
            }
        }
    }

    int gsize = 4;
    if (cmd_args[4] != -1){
        gsize = strtol(argv[cmd_args[4]], NULL, 10);
    }

    char line[strlen(argv[cmd_args[2]])];
    if (cmd_args[2] != -1 && !(strlen(argv[cmd_args[2]]) != gsize * gsize)){
        strcpy(line, argv[cmd_args[2]]);
    }
    else {
        fprintf(stderr, "Incorrect word or grid-size (now gridsize = %d) \n", gsize);
        return 84;
    }
    
    // if there was a word - look for it and end program
    if (cmd_args[6] != -1){
        int word_size = 0;
        while (argv[cmd_args[6]][word_size] != 0){
            word_size++;
        }
        char* word[word_size];
        strcpy(word, argv[cmd_args[6]]);
        
        if (word_finder(gsize, word_size, &line, &word)){
            print_grid(gsize, &line);
        }
        else {
            printf("The word %s is not in the grid\n", word);
        }
        return 0;
    }

    // if there was no word
    print_grid(gsize, &line);

    char *input;
    input = inputString(stdin, 10);
    int word_size = get_word_size(input);
    char * word;

    while (strcmp(input, "0")){
        if (word_finder(gsize, word_size, &line, input)){
            print_grid(gsize, &line);
        }
        else {
            printf("The word %s is not in the grid\n", input);
        }
        
        free(input);
        strcpy(line, argv[cmd_args[2]]);
        input = inputString(stdin, 10);
        word_size = get_word_size(input);
    }
    
    return 0;
}