/* prints a text in reverse order */

#include <stdio.h>

#define N 50

void reversal(char* arr);

int main(void)
{
    char arr[N];

    printf("Enter a message: ");
    reversal(arr);

    return 0;
}

void reversal(char* arr)
{
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i < N)
    {
        *(arr + i) = ch;
        i++;
    }
    while (i > N)
    {
        putchar(*(arr + i));
        i--;
    }
    printf("\n");
}