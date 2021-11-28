#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

char* duplicate(char *str);

int main(void) {
    char string[MAX_LEN + 1];

    printf("Enter a sentence: ");
    fgets(string, MAX_LEN+1, stdin);
    string[strlen(string) - 1] = '\0';

    printf("%s\n", duplicate(string));
}

char* duplicate(char *str) {
    int len = strlen(str);

    char *word = (char*)malloc(sizeof(char) * len);
    if (word == NULL) {
        return "\0";
    }
    
    strcpy(word, str);
    return word;
}