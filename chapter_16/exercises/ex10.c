#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void scale(struct rectangle *r, int x, int y);
bool in_rectangle(struct rectangle r, struct point p);


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

struct point center(struct rectangle r)
{
    struct point center;

    center.x = abs(r.upper_left.x + r.lower_right.x) / 2;
    center.y = abs(r.upper_left.y + r.lower_right.y) / 2;

    return center;
}

void scale(struct rectangle *r, int x, int y)
{
    (*r).upper_left.x += x;
    (*r).lower_right.x += x;

    (*r).upper_left.y += y;
    (*r).lower_right.y += y;
}

bool in_rectangle(struct rectangle r, struct point p)
{
    if ((p.x > r.upper_left.x && p.x < r.lower_right.x) &&
        (p.y > r.upper_left.y && p.y < r.lower_right.y))
        return true;
    return false;
}