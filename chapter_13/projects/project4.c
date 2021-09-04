/* Echoes command-line arguments in reverse order */

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i > 0; i--)
        printf("%s ", argv[i]);
    printf("\n");

    return 0;
}