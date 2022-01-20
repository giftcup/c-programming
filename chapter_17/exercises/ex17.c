#include <stdio.h>

int compare(void *p, void *q);

int main(void) {
    int values[100];

    for (int i = 0; i < 100; i++) {
        values[i] = i + 1;
    }

    qsort(values, sizeof(values)/sizeof(int)/2, sizeof(int), compare);
    for (int i = 0; i < sizeof(values)/sizeof(int); i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}

int compare(void *p, void *q) {
    return *(int*) q - *(int*) p;
}