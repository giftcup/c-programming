/* MEDIAN(x, y, z) calculates the median of 
** x, y and z.
*/

#include <stdio.h>

#define MEDIAN(x, y, z) (((x) + (y) + (z)) / 3.0f)

int main(void)
{
    printf("MEDIAN(3, 5, 15) = %.2lf\n", MEDIAN(3, 5, 15));

    return 0;
}