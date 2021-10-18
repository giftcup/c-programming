#include "inventory.h"
#include "update.h"

/*
 * update: Prompts the user to enter a part number.
 *         Prints an error message if the part doesn't
 *         exist; otherwise, prompts the user to enter
 *         change in quantity on hand and update the
 *         database.
 */
void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
        printf("Part not found.\n");
}