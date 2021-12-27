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
char select_operation(char str[]);

int main(void) {
    Stack *head;
    char *token, ch;
    int size_of_token;
    char operation;

    token = malloc(sizeof(char) * 1);
    size_of_token = 1;
    token[0] = '\0';

    printf("Enter expression in reverse polish notation: ");

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            head = malloc(sizeof(Stack) + size_of_token);
            strcpy(head->string, token);
            operation = select_operation(head->string);
            switch(operation) {
                case 'r':
                    pop();
                    break;
                case 'p':
                    push(atoi(head->string));
            }
            if (ch == '\n') {
                break;
            }   
            memset(token, 0, strlen(token));
            continue;
        }
        else {
            size_of_token++;
            token = realloc(token, sizeof(char) * size_of_token);
            strncat(token, &ch, 1);
        }
    }
    return 0;
}

char select_operation(char str[]) {

    if (strlen(str) == 1 && !(isdigit(str[0]))) {
        return 'r';
    }
    else {
        return 'p';
    }
}

void push(int digit) {
    printf("%d\n", digit);
}
int pop(void) {
    printf("Hello\n");
    return 0;
}