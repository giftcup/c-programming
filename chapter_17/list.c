#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* add_to_list(struct node* new_node, int value);
struct node* read_numbers(void);
void print_list(struct node* list);

int main(void)
{   
    struct node* list;

    list = read_numbers();
    print_list(list);

    return 0;
}

struct node* add_to_list(struct node* top, int value)
{
    struct node* new_node;

    new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = top;
    // top = new_node;

    return new_node;
}

struct node* read_numbers(void)
{
    struct node* top = NULL;
    int value;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;)
    {
        scanf("%d", &value);
        if (value == 0)
            return top;
        top = add_to_list(top, value);
    }
}

void print_list(struct node* list)
{
    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

struct node *search_list(struct node* list, int n)
{
    for (; list != NULL; list = list->next)
        if (list->value == n)
            return list;
    return NULL;
}

struct node* delete_from_list(struct node* list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next)
    ;
    
}