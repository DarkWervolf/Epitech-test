#include "word_finder.h"

int check_up(int* x, int* y, int gsize, char* line, char letter, int* checked_letters){
    if (line[letter_position(*x - 1, *y, gsize)] == letter && checked_letters[letter_position(*x - 1, *y, gsize)] == 0){
        *x = *x - 1;
        return 1;
    }
    return 0;
}

int check_down(int* x, int* y, int gsize, char* line, char letter, int* checked_letters){
    // printf("%c %c \n ", line[letter_position(*x + 1, *y, gsize)], word[i]);
    if (line[letter_position(*x + 1, *y, gsize)] == letter && checked_letters[letter_position(*x + 1, *y, gsize)] == 0){
        *x = *x + 1;
        return 1;
    }
    return 0;
}

int check_right(int* x, int* y, int gsize, char* line, char letter, int* checked_letters){
    if (line[letter_position(*x, *y + 1, gsize)] == letter && checked_letters[letter_position(*x, *y + 1, gsize)] == 0){
        *y = *y + 1;
        return 1;
    }
    return 0;
}

int check_left(int* x, int* y, int gsize, char* line, char letter, int* checked_letters){
    if (line[letter_position(*x, *y - 1, gsize)] == letter && checked_letters[letter_position(*x, *y - 1, gsize)] == 0){
        *y = *y - 1;
        return 1;
    }
    return 0;
}

void find_first_letter(int start_x, int start_y, int* x, int* y, int gsize, char* line, char* word)
{
    *x = start_x;
    *y = start_y;
    bool found = false;

    while (1){
        if (line[letter_position(*x, *y, gsize)] == word[0]){
            found = true;
            break;
        }
        else {
            if (*y < gsize)
                *y = *y + 1;       
            else if (*x < gsize) {
                *x = *x + 1;
                *y = 0;
            }
        }
    }

    // instead of return, it changes x and y
}

/*
    Finds next letter in line(=grid)
    - if found
        - changes x and y to letter's coord
        - returns 1
    - if not found
        - no changes to x and y
        - returns 0
*/
int find_next_letter(int* x, int* y, int gsize, char* line, char letter, int* checked_letters)
{
    // different cases for different positions on the table
        if (*x == 0 && *y == 0){
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x == 0 && *y > 0 && *y < gsize - 1){
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x > 0 && *x < gsize - 1 && *y == 0){
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*y == gsize - 1 && *x == 0){
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*y == gsize - 1 && *x > 0 && *x < gsize - 1){
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x == gsize - 1 && *y == 0){
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x == gsize - 1 && *y == gsize - 1){
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x == gsize - 1 && *y > 0 && *y < gsize - 1){
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        if (*x > 0 && *x < gsize - 1 && *y > 0 && *y < gsize - 1) {
            if (check_up(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_down(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_right(x, y, gsize, line, letter, checked_letters))
                return 1;
            if (check_left(x, y, gsize, line, letter, checked_letters))
                return 1;
        }
        return 0;
}

/*
    How it works:
        1. It finds the start letter
        2. It looks around (up, down, left, right) in possible directions and tries to find second letter
        3. If it succeeds - it moves to that letter and repeats 2, till the whole word is found.
        4. If not, it gets one step back and tries to find another letter, but not the one, used before.
            So if we have 2 'e' around letter 't', we first check one, and if we couldn't find anything around it, we come back,
            exclude this first 'e' and check the second 'e'
        5. If we come back to the first letter, we
*/
int word_finder(int gsize, int word_size, char* line, char* word)
{
    int* checked_letters = (int*) malloc(gsize * gsize * sizeof(int));
    for (int i = 0; i < gsize * gsize; i++)
        checked_letters[i] = 0;

    int x;
    int y;
    
    find_first_letter(0, 0, &x, &y, gsize, line, word);

    int* history_y = (int*) malloc(word_size * sizeof(int));
    int* history_x = (int*) malloc(word_size * sizeof(int));

    int i = 0;
    while (i < word_size){
        history_x[i] = x;
        history_y[i] = y;

        checked_letters[letter_position(x, y, gsize)] = 1;
        i++;

        // found the whole word
        if (i == word_size){
            for (int l = 0; l < i; l++){
                line[letter_position(history_x[l], history_y[l], gsize)] = 
                    toupper(line[letter_position(history_x[l], history_y[l], gsize)]);
            }
            return 1;
        }

        find_next_letter(&x, &y, gsize, line, word[i], checked_letters);

        // if no one 'if' worked => next letter is not found
        if (line[letter_position(x, y, gsize)] != word[i]){
            i = i - 1;
            checked_letters[letter_position(x, y, gsize)] = 1;
            for (int k = letter_position(x, y, gsize) + 1; k < sizeof(checked_letters); k++){
                checked_letters[k] = 0;
            }
            if (i == 0){
                if (!find_next_letter(&x, &y, gsize, line, word[i], checked_letters)){
                    if (y < gsize)
                        y++;       
                    else if (x < gsize) {
                        x++;
                        y = 0;
                    }
                    find_first_letter(x, y, &x, &y, gsize, line, word);
                }
                else {
                    continue;
                }
            }
            else {
                i--;
                x = history_x[i];
                y = history_y[i];
            }
        }
    }

    return 1;
}