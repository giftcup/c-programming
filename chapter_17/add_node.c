#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number;
    struct list *next_node;
} List;

void add_to_end(List** tracker, int number);
void delete_node(List** tracker, int number);
void print_node(List* head);
// void bubble_sort(List** tracker);
void swap(List** head);

int main(void)
{
    List *head, *tracker;
    int number;
    head = NULL;
    tracker = NULL;

    printf("Enter 0 to quit: ");
    for (;;)
    {
        scanf("%d", &number);
        if (number == 0)
            break;
        if (head == NULL)
        {
            add_to_end(&head, number);
            tracker = head;
            continue;
        }
        add_to_end(&tracker, number);
    }
    print_node(head);
    swap(&head);
    print_node(head);

    return 0;
}

void add_to_end(List** tracker, int number)
{
    List *new_node;
    new_node = (List*) malloc(sizeof(List));

    if (new_node == NULL)
    {
        printf("memory allocation failed in add_to_end\n");
        return;
    }
    new_node->number = number;

    if (*tracker == NULL)
        *tracker = new_node;
    else
    {
        (*tracker)->next_node = new_node;
        *tracker = new_node;
    }
    (*tracker)->next_node = NULL;
}

void delete_node(List** tracker, int number)
{
    List *cur, *prev;
    cur = prev = (List*)malloc(sizeof(List));

    for (cur = *tracker, prev = NULL; 
         cur != NULL && cur->number != number;
         prev = cur, cur = cur->next_node)
    ;
    if (cur == NULL) return;
    if (prev == NULL)
        *tracker = cur->next_node;
    else
        prev->next_node = cur->next_node;

    free(cur);
}

void print_node(List* head)
{
    for (; head != NULL; head = head->next_node)
        printf("%d->", head->number);
    if (head == NULL)
        printf("NULL\n");
}

void swap(List** head)
{
    List* next;

    next = (*head)->next_node;
    (*head)->next_node = next->next_node;
    next->next_node = (*head);
    (*head) = next;
}