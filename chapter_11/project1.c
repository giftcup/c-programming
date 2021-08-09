

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int* fives, int* ones);

int main(void)
{
    int amount;
    int twenties, tens, fives, ones;
    twenties = tens = fives = ones = 0;

    printf("Enter an amount in dollars: ");
    scanf("%d", &amount);
    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf ("Smallest number of \n");
    printf("$20 = %d\n$10 : %d\n$5 : %d\n$1 : %d\n", twenties, tens, fives, ones);

    return 0;

}

void pay_amount(int dollars, int *twenties, int *tens, int* fives, int* ones)
{
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars;
}