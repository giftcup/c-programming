#include <stdio.h>

int main(void)
{
    struct {int x, y;} x;
    struct {int x, y;} y;

    y.x = 10;
    y.y = 13;
    x.y = 15;
    x.x = 20;

    printf("%d %d %d %d\n", y.x, y.y, x.y, x.x);
}