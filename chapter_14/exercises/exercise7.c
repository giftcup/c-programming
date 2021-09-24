/* Using the ## symbol to give name to different
** functions
**/

#include <stdio.h>

typedef unsigned long unsigned_long;

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

GENERIC_MAX(unsigned_long)

int main(void)
{
    return 0;
}