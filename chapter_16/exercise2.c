#include <stdio.h>

struct number {
    int a;
};

void double_value(struct number * p);

int main(void)
{
    struct number p = {4};
    // p.a = 4
    
    double_value(&p);
    printf("New value of a in p: %d\n", p.a);

    return 0;
}

void double_value(struct number * p)
{
    // *ptr  
    // p->a *= 2;
    (*p).a *= 2;
}