#include <stdio.h>
#include <stdlib.h>

#define RECTANGLE 0
#define CIRCLE 1

struct point{
    int x;
    int y;
};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
};

void make_shape(struct shape* s, 
                int kind, 
                int x,
                int y,
                int height,
                int width,
                int radius
                );
void make_rectangle(struct shape* s, int height, int width);
void make_circle(struct shape* s, int radius);
double area(struct shape s);
struct shape move(struct shape s, int x, int y);
struct shape scale(struct shape s, double factor);
void print_area(struct shape s);


int main(void) 
{
    struct shape r, s, t;

    make_shape(&s, RECTANGLE, 3, 4, 4, 7, 7);
    make_shape(&r, CIRCLE, 0, 0, 3, 9, 3);
    // make_shape(&t, 9, 4, 4, 9, 8, 0);

    print_area(r);
    print_area(s);

    return 0;
}

void make_shape(struct shape* s, 
                int kind, 
                int x,
                int y,
                int height,
                int width,
                int radius
                )
{
    (*s).shape_kind = kind;
    (*s).center.x = x;
    (*s).center.y = y;

    if (kind == RECTANGLE)
        make_rectangle(s, height, width);
    else if (kind == CIRCLE)
        make_circle(s, radius);
    else
    {
        printf("\nShape not found\n");
        exit(EXIT_FAILURE);
    }
}

void make_rectangle(struct shape* s, int height, int width)
{
    (*s).u.rectangle.height = height;
    (*s).u.rectangle.width = width;
}

void make_circle(struct shape* s, int radius)
{
    (*s).u.circle.radius = radius;
}

double area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return (s.u.rectangle.height * s.u.rectangle.width);
    else if (s.shape_kind == CIRCLE)
        return ((22/7) * (s.u.circle.radius * s.u.circle.radius));
    else
        printf("\nShape not defined\n");
        exit(EXIT_FAILURE);
}

struct shape move(struct shape s, int x, int y)
{
    struct shape s1 = s;
    
    s1.center.x += x;
    s1.center.y += y;

    return s1;
}

struct shape scale(struct shape s, double factor)
{
    struct shape scale_shape;

    if (s.shape_kind == CIRCLE)
        scale_shape.u.circle.radius = (int) (s.u.circle.radius * factor);
    else if (s.shape_kind == RECTANGLE)
    {
        scale_shape.u.rectangle.height = (int) (s.u.rectangle.height * factor);
        scale_shape.u.rectangle.width = (int) (s.u.rectangle.width * factor);
    }
    else
    {  
        printf("\nShape not found\n");
        exit(EXIT_FAILURE);
    }

    return scale_shape;
}

void print_area(struct shape s)
{
    printf("Area of shape is: %.2lf\n", area(s));
}