#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

struct rectangle {
    struct point upper_left;
    struct point lower_right;
};

int area(struct rectangle r);
struct point center(struct rectangle r);

int main(void)
{

    return 0;
}

int area(struct rectangle r)
{
    int len, width;

    len = abs(r.upper_left.x - r.lower_right.x);
    width = abs(r.upper_left.y - r.lower_right.y);

    return (len * width);
}