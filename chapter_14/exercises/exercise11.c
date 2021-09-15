#include <stdio.h>

#define ERROR(...) fprintf(stderr, __VA_ARGS__);

int main(void)
{
    int index = 0;
    ERROR("Range error: index = %d\n", index);
}