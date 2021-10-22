#include <stdio.h>

#define N (int) (sizeof(array) / sizeof(array[0]))

int main(void)
{
    int array[] = {1, 2, 4, 5, 6, 7};
    printf("%d\n", N);
}