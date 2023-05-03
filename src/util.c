#include "util.h"
void print_grid(int gsize, char* line)
{
    int temp = 0;
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
            printf("%c ", line[letter_position(i, j, gsize)]);
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
        temp++;
    }
}

int letter_position(int i, int j, int gsize)
{
    if (i == 0){
        return j;
    }
    else {
        return i * gsize + j;
    }
}