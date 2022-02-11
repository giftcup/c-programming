#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "read_word.h"
#include "sort.h"

#define MAX_WORD_LEN 20
#define MAX_NUM_WORDS 3

int main(void) {
    char *words[MAX_NUM_WORDS];
    char word[MAX_WORD_LEN + 1];
    int num_words, j, word_len = 0;

    for (num_words = 0; num_words < MAX_NUM_WORDS ; num_words++) {
        printf("Enter word: ");
        word_len = read_string(word, MAX_WORD_LEN);

        if (!word_len)
            break;
        
        words[num_words] = malloc(sizeof(char) * MAX_WORD_LEN + 1);
        strcpy(words[num_words], word);
    }
    if (num_words == MAX_NUM_WORDS)
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
               "+++++++++++ Sorry, you can't put in more words :( ++++++++++++++\n"
               "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    sort(words, num_words);
    printf("In sorted order: ");
    for (j = 0; j < num_words; j++) {
        printf("%s ", words[j]);
    } putchar('\n');

    return 0;
}