// #include "util.c"
#include <stdio.h>
#include <stdlib.h>

void print_grid(int gsize, char* line);
int letter_position(int i, int j, int gsize);
char *inputString(FILE* fp, size_t size);
int get_word_size(char * str);