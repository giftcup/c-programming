#include <stdio.h>
#include "read_word.h"

int read_char(void) {
    int ch = getchar();

    if (ch == '\n' || ch == '\t') {
        return ' ';
    }
    return ch;
}

int read_string(char *word, int len) {
    int ch, pos = 0;

    // while((ch = read_char()) == ' ');

    while ((ch = read_char()) != ' ') {
        if (pos < len)
            word[pos] = ch;
        pos++;
    }
    word[pos] = '\0';
    // fflush(stdin);
    return pos;
}