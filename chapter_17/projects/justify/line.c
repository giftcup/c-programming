#include <stdio.h>
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
    Line *tmp = first_word;

    for (first_word = first_word->next; 
         tmp != NULL; 
         tmp = first_word,  first_word = first_word->next
        )
            free(tmp);
}

void add_word(const char *word)
{
    Line *new_word = malloc(sizeof(Line));
    Line *tracker = first_word;
    first_word = malloc(sizeof(Line));

    line_len += strlen(word);
    num_words++;
    
    strcpy(new_word->word, word);
    new_word->next = NULL;

    if (first_word == NULL) {
        first_word = new_word;
        return;
    }

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

        spaces_to_insert = extra_spaces / (num_words - 1);
        for (i = 0; i <= spaces_to_insert + 1; i++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
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
