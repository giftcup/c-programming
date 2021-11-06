#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number;
    struct list *next_node;
} List;

List* add_to_end(List* tracker, int number);

int main(void)
{
    List *head, *tracker;
    head = NULL;
    tracker = NULL;

    for (int i = 1; i < 6; i++)
    {
        if (head == NULL)
        {
            head = add_to_end(head, i);
            tracker = head;
            continue;
        }
        tracker->next_node = add_to_end(tracker, i);
        tracker = tracker->next_node;
    }

    for (; head != NULL; head = head->next_node)
    {
        printf("%d->", head->number);
    }
    if (head == NULL)
        printf("NULL\n");

    return 0;
}

List* add_to_end(List* tracker, int number)
{
    List *new_node;
    new_node = (List*) malloc(sizeof(List));

    if (new_node == NULL)
    {
        printf("memory allocation failed in add_to_end\n");
        return NULL;
    }
    new_node->number = number;

    if (tracker == NULL)
    {
        tracker = new_node;
    }

    else
    {
        tracker->next_node = new_node;
        tracker = new_node;
    }
    tracker->next_node = NULL;

    return tracker;
}