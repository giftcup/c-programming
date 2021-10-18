#include "inventory.h"
#include "insert.h"
#include "readline.h"

/*
 * insert: Prompts the user for information about a new
 *         part and then inserts the part into the
 *         database. Prints an error message ad returns 
 *         prematurely if the part already exists or the
 *         database is full.
 */
void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}