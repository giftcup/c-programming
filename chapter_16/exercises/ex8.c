#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

const struct color MAGENTA = {.red = 255, .blue = 255};

int main(void)
{
    printf("%d %d %d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    return 0;
}