#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack {
    int token;
    struct stack *next;
    char string[];
} Stack;

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);

int main (void) {
    char *token, ch;
    int size_of_token;
    Stack *head;

    token = malloc(sizeof(char) * 1);
    size_of_token = 1;
    token[0] = '\0';

    while ((ch = getchar())) {
        if (ch == ' ' || ch =='\n') {
            head = malloc(sizeof(Stack) + sizeof(char) * strlen(token));
            strcpy(head->string, token);
            memset(token, 0, strlen(token));
            printf("%s\n", head->string);
            if (ch == '\n') break;
            continue;
        } else {
            size_of_token++;
            token = realloc(token, sizeof(char) * size_of_token);
            strncat(token, &ch, 1);
            // printf("%s\n", token);
        }
    }
}

