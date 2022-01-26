/* Maintains a parts database (dynamic allocation version) */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 2

typedef struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
}Part;

int num_parts = 0; /* number of parts currently stored */

void instructions(void);
int find_part(int number, Part *inventory);
void insert(Part *inventory);
void search(Part *inventory);
void update(Part *inventory);
void print(Part *inventory);
int read_line(char str[], int n);

/*
** main: Prompts the user to enter an operation code,
**       then calls a funciton to perform the requested
**       action. Repeats until the user enters the
**       command 'q'. Prints an error message if the user
**       enters an illegal code.
*/
int main(void)
{
    char code;
    Part *inventory = (Part*) malloc(sizeof(Part) * MAX_PARTS);

    for(;;)
    {
        instructions();
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')       /* skips to end of line */
            ;
        switch (code) {
            case 'i': 
                insert(inventory);
                break;
            case 's':
                search(inventory);
                break;
            case 'p':
                print(inventory);
                break;
            case 'u':
                update(inventory);
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

void instructions(void) {
    printf("\n++++++++++++++++++++++++++++\n"
           "+++++   INSTRUCTIONS   +++++\n"
           "++++++++++++++++++++++++++++\n\n");
    printf("        Insert: i\n"
           "        Search: s\n"
           "        Update: u\n"
           "        Print:  p\n"
           "        Quit:   q\n\n");
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while(ch != '\n' && ch != EOF) {
        if (i < n) 
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
    
}

/**
 * find_part: Looks up a part number in the inventory array.
 *            Returns the array index if the part number is
 *            found; otherwise, returns -1.
 */ 

int find_part(int number, Part *inventory)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

/**
 * insert: Prompts the user for the informatio about a new
 *          part and then inserts the part into the
 *          database. Prints an error message and returns
 *          prematurely if the part already exists or the
 *          database is full.
 */ 
void insert(Part *inventory)
{
    int part_number;
    static int max_size = MAX_PARTS;

    if (num_parts == max_size) {
        max_size += MAX_PARTS;
        printf("Database is full; Adding more parts,\n");
        inventory = realloc(inventory, sizeof(Part) * max_size);
        printf("realloc size: %lu\n", sizeof(inventory));
        
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    fflush(stdin);

    if (find_part(part_number, inventory) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quatity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

/*
** search: Prompts the user to enter a part number, then
**         looks up the part in the database. If the part
**         exists, prints the name and quality on hand;
**         if not, prints an error message.
*/
void search(Part *inventory)
{
    int number, i;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
    }
    else {
        printf("Part not found\n");
    }
}

/*
** update: Prompts the user to enter a part number.
**         Prints an error message if the part doesn't exist;
**         otherwise, prompts the user to enter change in
**         quantity on hand and updates the database.
*/
void update(Part *inventory)
{
    int number, change, i;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory);
    
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else {
        printf("Part not found.\n");
    }
}


/* 
** print: Prints a listing of all parts in the database,
**        showing the part number, part name, and
**        quantity on hand. Part numbers will appear in
**        order in which they were inserted.
*/
void print(Part *inventory) {
    int i;

    printf("Part Number     Part Name                           \n");
    for (i = 0; i < num_parts; i++) {
        printf("%7d         %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}