#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack {
    int number;
    struct stack *next;
} Stack;

void make_empty(Stack **head);
int is_empty(void);
int is_full(void);
void push(Stack **head, int num);
void pop(Stack ** head, char op);
char select_operation(char str[]);
void allocate(Stack **node);
void print_stack(Stack *node);
int pop_num(Stack **head);

int main(void) {
    Stack *head, tracker;
    char *token, ch;
    int size_of_token;
    char operation;

    token = malloc(sizeof(char) * 1);
    size_of_token = 1;
    token[0] = '\0';
    head = NULL;

    printf("Enter expression in reverse polish notation: ");

    while ((ch = getchar())) {
        if (ch == ' ' || ch == '\n') {
            operation = select_operation(token);
            switch(operation) {
                case 'r':
                    pop(&head, token[0]);
                    break;
                case 'p':
                    push(&head, atoi(token));
            }
            if (ch == '\n') {
                make_empty(&head);
                break;
            }   
            memset(token, 0, strlen(token));
            size_of_token = 1;
            token = realloc(token, sizeof(char) * size_of_token);
            continue;
        }
        else {
            size_of_token++;
            token = realloc(token, sizeof(char) * size_of_token);
            strncat(token, &ch, 1);
        }
    }
    print_stack(head);
    return 0;
}

void allocate(Stack **node) {
    *node = malloc(sizeof(Stack));
    if (*node == NULL) {
        printf("memalloc failed in allocate\n");
        exit(EXIT_FAILURE);
    }
}

char select_operation(char str[]) {

    if (strlen(str) == 1 && !(isdigit(str[0]))) {
        return 'r';
    }
    else {
        return 'p';
    }
}

void push(Stack **head, int num) {
    Stack *new_node;

    if (*head == NULL) {
        allocate(head);
        (*head)->number = num;
        return;
    }
    allocate(&new_node);
    new_node->number = num;
    new_node->next = *head;
    *head = new_node;
}

void pop(Stack ** head, char op) {
    int num1, num2, result;
    
    num1 = pop_num(head);
    num2 = pop_num(head);

    switch (op) {
        case '+':
            result = num2 + num1;
            break;
        case '-':
            result = num2 - num1;
            break;
        case '/':
            result = num2 / num1;
            break;
        case '*':
            result = num2 * num1;
            break;
        case '%':
            result = num2 - num1;
            break;
    }
    push(head, result);
    printf("result: %d\n", (*head)->number);
}

int pop_num(Stack **head) {
    Stack *temp = *head;
    int num = (*head)->number;

    (*head) = (*head)->next;
    free(temp);
    return num;
}

void make_empty(Stack **head) {
    int final = pop_num(head);

    printf ("final result: %d\n", final);
}

void print_stack(Stack *node) {
    for (; node != NULL; node = node->next) {
        printf("%d->", node->number);
    }
    printf("NULL\n");
}