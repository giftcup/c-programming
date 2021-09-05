/* Description: Printing the English word for a two digit number.
** Source: C Programming A Modern Approach
*/

#include <stdio.h>

int main(void)
{
    int number, first, second;
    char *teens[] = {"ten", "eleven", "twelve", "thirteen",
                    "fourteen", "fifteen", "sixteen", "seventeen",
                    "eighteen", "nineteen"};
    char *first_digit[] = {"twenty", "thirty", "fourty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"};
    char *second_digit[] = {"one", "two", "three", "four", "five", 
                            "six", "seven", "eight", "nine"};
    
    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    second = number % 10; // gets last number
    first = number / 10; // gets first number

    printf("You entered the number ");
    switch (first)
    {
        case 1:
            printf("%s\n", teens[second]);
            break;

        default:
            printf("%s", first_digit[first - 2]);
            if (second != 0)
                printf("-%s\n", second_digit[second - 1]);
            else 
                printf("\n");
    }

    return 0;
}