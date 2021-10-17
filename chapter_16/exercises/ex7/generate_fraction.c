#include "generate_fraction.h"
#include "ex7.h"

void print(struct fraction f)
{
    printf("%d/%d\n", f.numerator, f.denominator);
}

struct fraction make_fraction(int n, int d)
{
    struct fraction f = {n, d};
    return f;
}

void reduce_fraction(struct fraction *f)
{
    int i = 1, gcd;

    while (i <= f->denominator && i <= f->numerator)
    {
        if (f->denominator % i == 0 && f->numerator % i == 0)
            gcd = i;
        i++;
    }
    f->denominator /= gcd;
    f->numerator /= gcd;
}