#include <stdio.h>

#define SIZE 40

enum type_t {
    EM,
    SS
};

struct pinball_machine {
    char name[SIZE + 1];
    int year;
    enum type_t type;
    int players;
};