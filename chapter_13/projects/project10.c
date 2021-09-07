/* 
** Takes first name and last name from user and displays 
** `first_name_initial, last_name`
*/

#include <stdio.h>

int main(void)
{
    char first, ch;

    printf("Enter a first and last name: ");
    
    first = getchar();

    while ((ch = getchar()) != ' ')
        ch = ' '; 
    while ((ch = getchar()) != '\n')
    {
        if (ch != ' ')
        {
            putchar(ch);
        }
    }
    putchar(',');
    putchar(first);
    putchar(' ');
    putchar('\n');
}