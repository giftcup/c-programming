/* Prints the line number on which LINE_FILE is
** called and the file name too.
*/

#include <stdio.h>

#define LINE __LINE__
#define STRINGIZE(x) #x
#define LINE_FILE ("Line " STRINGIZE(LINE) " of file " __FILE__)

int main(void)
{
     const char *str = LINE_FILE;
     printf("%s\n", str);
}