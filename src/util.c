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

char *inputString(FILE* fp, size_t size){
    //The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

int get_word_size(char * str)
{
    int word_size = 0;
    while (str[word_size] != 0){
        word_size++;
    }
    return word_size;
}