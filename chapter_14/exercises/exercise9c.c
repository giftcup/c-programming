/* POLYNOMIAL(x): calculates the value of x passed 
** to the polynomial 
** 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
**/

#include <stdio.h>
#include <math.h>

#define POLYNOMIAL(x) ((3 * pow(x, 5)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - (pow(x, 2)) + (7 * x) - 6)

int main(void)
{
    printf("POLYNOMIAL(0) = %d\n", (int) POLYNOMIAL(1));

    return 0;
}