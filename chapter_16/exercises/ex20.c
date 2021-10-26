#include <stdio.h>

enum {
    NORTH,
    SOUTH,
    EAST,
    WEST
} direction;

int x, y;

int main(void)
{
    switch (direction)
    {
        case EAST:
            x++;
            break;
        case WEST:
            x--;
            break;
        case SOUTH:
            y++;
            break;
        case NORTH:
            y--;
            break;
    }
}