#include <stdio.h>

typedef struct{
    double real, imaginary;
} Complex;

Complex c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

Complex make_complex(double real, double imaginary);
Complex add_complex(Complex s1, Complex s2);
void print_struct(Complex c);

int main(void)
{
    Complex c4, c5;

    c4 = make_complex(2.3, 7.8);
    print_struct(c4);
    c5 = add_complex(c1, c2);
    print_struct(c5);

    return 0;
}

Complex make_complex(double r, double i)
{
    Complex c4;
    c4.real = r;
    c4.imaginary = i;

    return c4;
}

Complex add_complex(Complex s1, Complex s2)
{
    Complex result;
    
    result.real = s1.real + s2.real;
    result.imaginary = s1.imaginary + s2.imaginary;

    return result;
}

void print_struct(Complex c)
{
    printf("%.3lf %.3lf\n", c.real, c.imaginary);
}