/* Using the ## symbol to give name to different
** functions
**/

#include <stdio.h>

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? c : y;       \
}

int main(void)
{
    //GENERIC_MAX(long)
}