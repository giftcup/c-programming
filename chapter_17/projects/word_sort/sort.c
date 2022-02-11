#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void sort(char **words, int num_words) {
    int i, j;

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < num_words-i; j++)
            if (strcmp(words[j], words[j+1]) > 0)
                swap(words[j], words[j+1]);
    }
    
    return;
}

void swap(char *word1, char *word2) {
    char *tmp_word;

    tmp_word = malloc(sizeof(char) * strlen(word1) + 1);
    
    strcpy(tmp_word, word1);
    
    strcpy(word1, word2);
    
    strcpy(word2, tmp_word);
    
}