/* Evidence of incorrect results when arguments with
** side effects are passed to macros. The macro eva-
** luates the argument more than once, hence, 
** producing unexpected results
*/

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z'? (c) - 'a' + 'A': (c))

int main(void)
{
    char s[5];
    int i;

    strcpy(s, "a5c7");
    i = 0;
    putchar(TOUPPER(s[i]));
    putchar('\n');

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
    putchar('\n');

    return 0;
}