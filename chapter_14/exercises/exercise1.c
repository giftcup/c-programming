/* Checks the functionality of particular macros */

#include <stdio.h>

#define CUBE(x) (x * x * x) //finds the cube of x
#define REMAINDER(n) (n % 4) //finds the remainder when n is divided by 4
#define COMPARE(x, y) (x * y < 100 ? 1 : 0)

int main(void)
{
    /* CUBE() works for all cases */
    printf("3 squared = %d\n", CUBE(3));
    printf("3.5 squared = %.2lf\n", CUBE(3.5));
    printf("-3 squared = %d\n", CUBE(-3));
    
    /* the REMAINDER macro fails when a floating point number is used */
    printf("The remainder of 8 by 4: %d\n", REMAINDER(8));
    printf("The remainder of -9 by 4: %d\n", REMAINDER(-9));

    /* COMPARE() works for all cases */
    printf("COMPARE(3, 4): %d\n", COMPARE(3, 4));
    printf("COMPARE(89.9, 16.7): %d\n", COMPARE(89.9, 16.7));
    printf("COMPARE(89.9, -16.7): %d\n", COMPARE(89.9, -16.7));

    return 0;
}