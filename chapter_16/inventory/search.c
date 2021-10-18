#include "inventory.h"
#include "search.h"

/*
 * search: Prompts the userto enter a part number, 
 *         then looks up the part in the database. If the part
 *         exists, print the name and the quantity on hand; 
 *         if not, printd an error message.
*/
void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i =  find_part(number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
        printf("Part not found.\n");
}