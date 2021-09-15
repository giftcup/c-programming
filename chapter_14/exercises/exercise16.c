#include <stdio.h>

#define INDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void)
{
    INDENT(foo);
}