#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number;
    struct list *next_node;
} List;

void add_to_end(List** tracker, int number);
void delete_node(List** tracker, int number);
List* delete(List* head, int number);
void print_node(List* head);
void bubble_sort(List** tracker);
void swap(List** head);
void print_reverse(List* head);

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
    head = delete(head, 5);
    print_node(head);
    // for (List* ptr = head; ptr->next_node != NULL && ptr != NULL; ptr = ptr->next_node)
    // List* ptr = head;
    // printf("%d %d\n", head->number, ptr->number);
    // ptr = ptr->next_node;
    // printf("%d %d\n", head->number, ptr->number);
    //     // swap(&head);
    // tracker = head;
    // bubble_sort(&tracker);
    // print_node(head);
    // print_reverse(head);

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

/**
 * @brief Deletes a node from a list using one pointer
 * @param head pointer to the head of the list
 * @param number element at node to be deleted
 * @return pointer to the head
 */ 
List* delete(List* head, int number) 
{
    List *tracker = head;

    if (head->number == number) {
        head = head->next_node;
        free(tracker);
        return head;
    }

    for (; tracker->next_node != NULL; 
        tracker = tracker->next_node) {
        if (tracker->next_node->number == number) {
            tracker->next_node = tracker->next_node->next_node;
            break;
        }    
    }
    return head;
}

void print_node(List* head)
{
    for (; head != NULL; head = head->next_node)
        printf("%d->", head->number);
    if (head == NULL)
        printf("NULL\n");
}

void bubble_sort(List** tracker)
{
    List *next;

    for (next = (*tracker)->next_node; 
         next != NULL && *tracker != NULL; 
         *tracker = next, next = (*tracker)->next_node)
    {
        if ((*tracker)->number > next->number)
            swap(tracker);
    }
}

void swap(List** tracker)
{
    List* next;

    next = (*tracker)->next_node;
    (*tracker)->next_node = next->next_node;
    next->next_node = (*tracker);
    (*tracker) = next;
}

void print_reverse(List* head)
{
    if (head == NULL) {
        return;
    }
    print_reverse(head->next_node);
    printf("%d ", head->number);
}