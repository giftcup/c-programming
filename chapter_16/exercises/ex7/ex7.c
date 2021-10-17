#include "ex7.h"
#include "operation.h"
#include "generate_fraction.h"

int main(void)
{
    struct fraction a, b, c;
    int numerator, denominator;

    printf("Enter a fraction (numerator/denominator): ");
    scanf("%d/%d", &numerator, &denominator);
    a = make_fraction(numerator, denominator);

    reduce_fraction(&a);
    printf("Reduced fraction is ");
    print(a);

    printf("Enter a fraction (numerator/denominator): ");
    scanf("%d/%d", &numerator, &denominator);
    a = make_fraction(numerator, denominator);
    printf("Enter another fraction (numerator/denominator): ");
    scanf("%d/%d", &numerator, &denominator);
    b = make_fraction(numerator, denominator);
   
    c = add_fraction(a, b);
    printf("Addition result: ");
    print(c);

    c = subtract_fractions(a, b);
    printf("Subtraction result: ");
    print(c);

    c = multiply_fractions(a, b);
    printf("Multiplication result: ");
    print(c);

    c = divide_fractions(a, b);
    printf("Division result: ");
    print(c);

    return 0;
}