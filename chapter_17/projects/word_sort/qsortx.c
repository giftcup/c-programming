#include <stdlib.h>
#include "qsortx.h"

int compare(void *p, void *q);

void qsortx(char **words, int num, int size) {
    qsort(words, num, size, compare);
}

int compare(void *p, void *q) {
    return *(char*)p - *(char*)q
;}