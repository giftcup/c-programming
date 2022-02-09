#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAXA_LINE_LEN 60

typedef struct line {
    char *word;
    struct line *next;
} Line;

Line *first_word = NULL;

int line_len = 0;
int num_words =0;

void clear_line(void)
{
    Line *tmp;

    if(first_word == NULL)
        return;
    
    // Removing all words from a line
    for (tmp = first_word->next; tmp != NULL; 
         first_word = tmp, tmp = tmp->next
        )
            free(first_word);
        first_word = NULL;
    
    line_len = 0;
    num_words = 0;
    
}

void add_word(const char *word)
{
    Line *new_word = malloc(sizeof(Line));
    Line *tracker = malloc(sizeof(Line));

    line_len += strlen(word);
    num_words++;
    new_word->word = malloc (sizeof(char) * strlen(word) + 1);

    strcpy(new_word->word, word);
    new_word->next = NULL;

    if (first_word == NULL) {
        first_word = new_word;
        return;
    }

    tracker = first_word;
    while (tracker->next != NULL)
        tracker = tracker->next;
    tracker->next = new_word;
}

int space_remaining(void)
{
    return MAXA_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i;
    Line *tmp;

    extra_spaces = MAXA_LINE_LEN - line_len;
    for (tmp = first_word; tmp != NULL; tmp = tmp->next) {
        printf("%s", tmp->word);

        spaces_to_insert =  num_words / (extra_spaces + 1);
        if (extra_spaces == 0)
            spaces_to_insert = 0;
        
        for (i = 1; i <= spaces_to_insert + 1; i++)
            putchar(' ');
        extra_spaces += spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void)
{
    for (Line *tmp = first_word; tmp != NULL; tmp = tmp->next)
        printf("%s ", tmp->word);
    printf("\n");
}
