#include <stdio.h>

#define NAME_LEN 20
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};


extern int num_parts;
extern struct part inventory[MAX_PARTS];

int find_part(int number);
void print(void);