#include <stdio.h>

// #define INDENT(x) PRAGMA(ident #x)
// #define PRAGMA(x) _Pragma(#x)

int main(void)
{
    #pragma GCC dependency "parse.y - " __FILE__ " this file is older than parse.y"
}