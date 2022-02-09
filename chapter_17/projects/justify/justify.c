/* Formats a file of text */

#include "line.h"
#include "word.h"
#include <stdio.h>

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    for (;;) 
    {
        word_len = read_word(word, MAX_WORD_LEN+1);

        if (word_len == 0) 
        {
            flush_line();
            return 0;
        }
        if (word_len > space_remaining())
        {
            write_line();
            clear_line();
        }
        // word_len less than space remaining, add word
        // to line
        add_word(word);
    }
}