#include "operation.h"
#include "generate_fraction.h"
#include "ex7.h"

struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction result;
    
    result.numerator = (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator);
    result.denominator = f1.denominator * f2.denominator;

    reduce_fraction(&result);
    
    return result;
}

struct fraction subtract_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result;
    
    result.numerator = (f1.numerator * f2.denominator) - (f1.denominator * f2.numerator);
    result.denominator = f1.denominator * f2.denominator;

    reduce_fraction(&result);
    
    return result;
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result;
    
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;

    reduce_fraction(&result);
    
    return result;
}

struct fraction divide_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result;
    
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;

    reduce_fraction(&result);
    
    return result;
}