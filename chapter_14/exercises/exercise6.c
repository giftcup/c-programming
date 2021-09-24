/* DISP(f, x) expands a call to printf that
** displays the value of the function f when
** called with argument x
** DISP(f, x, y) functions like DISP(f,x) but
** for functions with two arguments
*/

#include <stdio.h>
#include <math.h>

#define DISP(f,x) (printf(#f"(%g) = %g\n", (double)x, f((double)x)))

#define DISP2(f,x,y) (printf(#f"(%g, %g) = %g\n", (double)x, (double)y, f(x, y)))

int main(void)
{
    DISP(sqrt, 3);
    
    DISP2(pow, 9, 2);

    return 0;
}