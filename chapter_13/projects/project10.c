/* 
** Takes first name and last name from user and displays 
** `first_name_initial, last_name`
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 30  //length of the name
#define IN_LEN 15 //length of the first and last name

void reverse_name(char *name);
int read_line(char *name,int size);

int main(void)
{
    char name[LEN + 1];

    printf("Enter a first and last name: ");
    read_line(name, LEN);
    reverse_name(name);

    //printf("%s\n", name);
    
}

/* read_line: writes the name entered by a user into
**            a string and returns i, the length of
**            the string.
*/
int read_line(char *name, int size)
{
    int ch, i;

    i = 0;
    while ((ch = getchar()) != '\n')
        if (i < size)
            name[i++] = ch;
    name[i] = '\0';

    return i;
}

/* reverse_name: Puts the 'last name, firstname.'
**               Gets the string `name`.
**               returns.
*/
void reverse_name(char *name)
{
    char *name_ptr = name, first_name_initial;

    while (*name_ptr == ' ') 
        name_ptr++;
    first_name_initial = *name_ptr++;
    while(*name_ptr && *name_ptr++ != ' ')
        ;
    while (*name_ptr == ' ') 
        name_ptr++;
    while (*name_ptr && *name_ptr != '\n')
        printf("%c", *name_ptr++);
    while (*name_ptr == ' ') 
        ;
    
    printf(", %c.\n", first_name_initial);
}

/*void reverse_name(char *name)
{
    char firstname[IN_LEN + 1], lastname[IN_LEN + 1];
    
    sscanf(name, "%s %s", firstname, lastname);
    printf("%s %s\n", firstname, lastname);
    memset(name, 0, strlen(name));

    sprintf(name, "%s, %c.\n", lastname, firstname[0]);
    printf("%s\n", name);

}
*/