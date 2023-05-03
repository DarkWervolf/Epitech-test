#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "util.h"


int word_finder(int gsize, int word_size, char* line, char* word);

int check_up(int* x, int* y, int gsize, char* line, char letter, int* checked_letters);

int check_down(int* x, int* y, int gsize, char* line, char letter, int* checked_letters);

int check_right(int* x, int* y, int gsize, char* line, char letter, int* checked_letters);

int check_left(int* x, int* y, int gsize, char* line, char letter, int* checked_letters);

int find_first_letter(int start_x, int start_y, int* x, int* y, int gsize, char* line, char* word);

int find_next_letter(int* x, int* y, int gsize, char* line, char letter, int* checked_letters);