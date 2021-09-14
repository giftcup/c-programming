/* Calculates the average of two numbers and the
** area of a rectangle
**/

#include <stdio.h>

#define AVG(x, y) (((x) + (y)) / 2)
#define AREA(x, y) ((x) * (y))

int main(void)
{
    int avg = AVG(5-2, 6);
    int area = AREA(10+2, 6);

    printf("Average: %d\n", avg);
    printf("Area: %d\n", area);

    return 0;
}