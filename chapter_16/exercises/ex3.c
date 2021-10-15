#include <stdio.h>

struct complex{
    double real, imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex s1, struct complex s2);
void print_struct(struct complex c);

int main(void)
{
    struct complex c4, c5;

    c4 = make_complex(2.3, 7.8);
    print_struct(c4);
    c5 = add_complex(c1, c2);
    print_struct(c5);

    return 0;
}

struct complex make_complex(double r, double i)
{
    struct complex c4;
    c4.real = r;
    c4.imaginary = i;

    return c4;
}

struct complex add_complex(struct complex s1, struct complex s2)
{
    struct complex result;
    
    result.real = s1.real + s2.real;
    result.imaginary = s1.imaginary + s2.imaginary;

    return result;
}

void print_struct(struct complex c)
{
    printf("%.3lf %.3lf\n", c.real, c.imaginary);
}