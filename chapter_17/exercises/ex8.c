#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack {
    int token;
    struct stack *next;
} Stack;

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);

int main (void) {
    char token;
    Stack *head;

    while ((token = getchar()) != '\n') {
        if (isalnum(token)) {
            printf("yay!\n");
            // push(head);
        }
    }
}

