/* Description: Reduces a fraction to the lowest terms using pointers.
** Source: C Programming A Modern Approach
*/

#include <stdio.h>

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator);

int main(void)
{
    int numerator, denominator;
    int reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    reduced_numerator = numerator;
    reduced_denominator = denominator;
    
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);
}

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator)
{
    if (denominator > numerator)
    {
        int temp = denominator;
        denominator = numerator;
        numerator = temp;
    }

    do
    {
        if(denominator == 0)
        {
            *reduced_numerator /= numerator;
            *reduced_denominator /= numerator;
            printf("In lowest terms: %d/%d\n", *reduced_numerator, *reduced_denominator);
            return;
        }
        else
        {
            int t = numerator;
            numerator = denominator;
            denominator = t % denominator;
        }
    } while (denominator >= 0);
}