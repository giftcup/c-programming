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
    char* ptr;
    char ch;

    ptr = arr;
    while ((ch = getchar()) != '\n' && ptr < arr + N)
    {
        *ptr++ = ch;
    }
    while (ptr >= arr)
    {
        putchar(*ptr--);
    }
    printf("\n");
}