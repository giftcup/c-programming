#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

char* duplicate(char *str);

int main(void) {
    char string[MAX_LEN + 1];

    printf("Enter a word not more than 30 character: ");
    scanf("%s", string);

    
    printf("%s\n", duplicate(string));
}

char* duplicate(char *str) {
    int len = strlen(str);

    char *word = (char*)malloc(sizeof(char) * len);
    
    strcpy(word, str);
    return word;
}