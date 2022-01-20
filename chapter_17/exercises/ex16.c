#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int func(int num);

int main(void) {
    int start, end;

    start = 10;
    end = 100;

    printf("Answer: %d\n", sum(func, start, end));
    return 0;
}

int sum(int (*f)(int), int start, int end) {
    int sum = 0;

    for (int i = start; i <= end; i++) {
        sum += (*f)(i);
    }
    return sum;
}

int func(int num) {
    return num + 2;
}