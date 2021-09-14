/* Prints the line number on which LINE_FILE is
** called and the file name too.
*/

#include <stdio.h>

#define LINE __LINE__
#define LINE_FILE ("Line %d of file %s", __LINE__, __FILE__)

int main(void)
{
     const char *str = LINE_FILE;
     printf("%s\n", str);
}