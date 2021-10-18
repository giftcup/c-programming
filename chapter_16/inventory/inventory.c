#include "readline.h"
#include "inventory.h"
#include "insert.h"
#include "search.h"
#include "update.h"

/*
 * main: Prompts the user to enter an operation code,
 *       then calls a function to perform the requested 
 *       action. Repeats until the user enters the 
 *       command 'q'. Prints an error message if the user
 *       enters an illegal code.
*/
int main(void)
{
    char opcode;
    num_parts = 0;
    for (;;)
    {
        printf("\nEnter operation code: ");
        scanf(" %c", &opcode);
        fflush(stdin);
        // while (getchar() != '\n') 
        //     ;

        switch(opcode)
        {
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
                printf("Command not valid\n");
        }
    }
}

/*
 * find_part: Looks up a number in the inventory
 *            array, Returns the array index if the part
 *            number is found; otherwise, return -1
 */
int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}


/*
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and
 *        quantity on hand. Parts are printed in the order
 *        in which ther were entered into the database.
 */
void print(void)
{
    int i;

    printf("Part Number     Part Name                    "
            "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d         %-25s%11d\n", inventory[i].number,
                inventory[i].name, inventory[i].on_hand);
}