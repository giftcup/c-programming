#include <stdio.h>
#include <stdbool.h>

#define UPPER 255
#define LOWER 0
#define DIV 0.7

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int make_each_color(int color);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
int brighter_rules(int color);
struct color darker(struct color c);
int darker_rules(int color);
void print_color(struct color c);

int main(void)
{
    struct color P = make_color(25, 84, 100);
    struct color Q = make_color(0, 0, 0);
    struct color R = make_color(255, 90, 254);

    print_color(P);
    print_color(Q);
    print_color(R);

    P = brighter(P);
    Q = brighter(Q);
    R = brighter(R);

    printf("\n");
    print_color(P);
    print_color(Q);
    print_color(R);

    P = darker(P);
    Q = darker(Q);
    R = darker(R);
    
    printf("\n");
    print_color(P);
    print_color(Q);
    print_color(R);

    return 0;
}

struct color make_color(int red, int green, int blue)
{
    struct color color;
    
    color.red = make_each_color(red);
    color.green = make_each_color(green);
    color.blue = make_each_color(blue);

    return color;
}

int make_each_color(int color)
{
    if (color < LOWER)
        color = LOWER;
    else 
        color = color > UPPER ? UPPER : color;

    return color;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    if (color1.red == color2.red &&
        color1.green == color2.green &&
        color1.blue == color2.blue
        )
        return true;
    return false;
}

struct color brighter(struct color c)
{
    c.red = brighter_rules(c.red);
    c.green = brighter_rules(c.green);
    c.blue = brighter_rules(c.blue);

    if (c.red == LOWER &&
        c.blue == LOWER &&
        c.green == LOWER
        )
    {
        c.red = 3;
        c.green = 3;
        c.blue = 3;
    }

    return c;      
}

int brighter_rules(int color)
{
    if (color > 0 && color < 3)
        color = 3;
    color = (int) (color / DIV);
    if (color > UPPER)
        color = UPPER;
    
    return color;
}

struct color darker(struct color c)
{
    c.red = darker_rules(c.red);
    c.green = darker_rules(c.green);
    c.blue = darker_rules(c.blue);

    return c;
}

int darker_rules(int color)
{
    color = (int) (color * DIV);
    
    return color;
}

void print_color(struct color c)
{
    printf("%d, %d, %d\n", c.red, c.green, c.blue);
}