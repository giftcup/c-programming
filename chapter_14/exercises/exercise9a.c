/* CHECK(x, y, n) Has the value 1 if both x and y
** fall between 0 and n - 1 inclusize.
*/

#include <stdio.h>

#define CHECK(x, y, n) (((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)) ? 1 : 0)

int main(void)
{
    printf("%d\n", CHECK(3, 6, 10));
    printf("%d\n", CHECK(6, 3, 4));

    return 0;
}