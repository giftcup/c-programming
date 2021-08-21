/* prints a text in reverse order */

#include <stdio.h>

#define N 50

void reversal(int arr[N]);

int main(void)
{
    int arr[N];

    printf("Enter a message: ");
    reversal(arr);

    return 0;
}

void reversal(int arr[N])
{
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i < N)
        arr[i++] = ch;

    while (i >= 0)
    {
        putchar(arr[i--]);
    }
    printf("\n");
}