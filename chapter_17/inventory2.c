#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;      /* points to first part */

void instructions(void);
struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
int read_line(char str[], int n);
int compare_parts(const void *p, const void *q);

/**
 * @brief Calls a function to be performed on the inventory
 *        based on what command the user enters.
 * @param void
 */
int main(void)
{
    char code;

    for(;;)
    {
        instructions();

        printf("Enter operation code: ");
        scanf(" %c", &code);
        fflush(stdin);

        switch (code) {
            case 'i': 
                insert();
                break;
            case 's':
                search();
                break;
            case 'e':
                erase();
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

/**
 * @brief instructions prints out the instructions to the
 *        user.
 * @param void
 */ 
void instructions(void) {
    printf("\n++++++++++++++++++++++++++++\n"
           "+++++   INSTRUCTIONS   +++++\n"
           "++++++++++++++++++++++++++++\n\n");
    printf("        Insert: i\n"
           "        Search: s\n"
           "        Update: u\n"
           "        Print:  p\n"
           "        Erase:  e\n"
           "        Quit:   q\n\n");
}


/**
 * @brief read_line reads the name of the part and stores
 *        in a string.
 * @param str the string to be written to
 * @param n the maximum size of the string
 */
int read_line(char str[], int n) {
    int ch, i = 0;

    while((ch = getchar()) && (ch != '\n' && ch != EOF)) {
        if (i < n) 
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
    
}

/**
 * @brief Looks up a part number in the inventory. If it
 *        exists, it returns the address of the part;
 *        otherwise, it returns NULL.
 * @param void
 */

struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory;
         p != NULL & number > p->number;
         p = p->next)
    ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/**
 * @brief Adds information about a new part gotten to 
 *        from the user to the inventory if the part
 *        does not already exist.
 * @param void
 */
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    fflush(stdin);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
    ;
    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exist.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/**
 * @brief Prompts the user to enter a part number, then
 *        looks it up in the inventory. If it exists, it
 *        prints the name and quantity on hand; if not,
 *        it prints an error message.
 * @param void
 */
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } 
    else
        printf("Part not found.\n");
}


/**
 * @brief erase deletes a part from the inventory list
 * @param void
 * @return void
 */
void erase(void) {
    int part_num;
    struct part *cur, *prev;

    printf("Enter part number: ");
    scanf("%d", &part_num);
    
    for (cur = inventory, prev = NULL; 
         cur != NULL && cur->number != part_num;
         prev = cur, cur = cur->next);
    
    if (cur == NULL) {
        printf("Part does not exist!\n");
        return;
    }
    else if (prev == NULL) {
        inventory = inventory->next;
        free(cur);
    }
    else {
        prev->next = cur->next;
        free(cur);
    }
    printf("Part deleted\n\n");
    return;
}


/**
 * @brief update Prompts the user to enter a part number.
 *        Prints an error message if the part doesn't 
 *        exist;
 *        Otherwise, prompts the user to enter the change
 *        in quantity on hand and updates the database
 *        accordingly.
 * @param void
 * @return void
 */
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found.\n");
}

/**
 * @brief Prints a listing of all parts in the database,
 *        showing the part number, part name and quantity
 *        on hand. Part numbers will appear in ascending
 *        order.
 * @param void
 */
void print(void) {
    struct part *p;
    printf("Part Number     Part Name                       "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p=p->next)
        printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
}