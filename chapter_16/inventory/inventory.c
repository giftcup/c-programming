/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')       /* skips to end of line */
            ;
        switch (code) {
            case 'i': 
                insert();
                break;
            case 's': 
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n"); 
        }
        printf("\n");
    }
}

int find_part(int number) {
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
        return -1;
}

void insert(void) {
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Datanase is full: can't add more parts.\n");
    }
}