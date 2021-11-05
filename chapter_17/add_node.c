#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number;
    struct list *next_node;
} List;

void add_to_end(List* tracker, int number);

int main(void)
{
    List *head, *tracker;
    head = NULL;
    tracker = NULL;

    head = (List*) malloc(sizeof(List));
    head->number = 1;
    head->next_node = NULL;
    tracker = head;

    for (int i = 2; i < 6; i++)
         add_to_end(tracker, i);

    for (int i = 1; i < 6  && head != NULL; i++)
    {
        printf("%d->", head->number);
        head = head->next_node;
    }
    if (head == NULL)
        printf("NULL\n");

    return 0;
}

void add_to_end(List* tracker, int number)
{
    List *new_node;
    new_node = (List*) malloc(sizeof(List));

    if (new_node == NULL)
    {
        printf("memory allocation failed in add_to_end\n");
        return;
    }

    new_node->number = number;
    tracker->next_node = new_node;
    tracker = new_node;
    tracker->next_node = NULL;
}