/* prints a text in reverse order */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 50

int read_line(char *message, int n);
void reverse_message(char* message);
//void swap_pos(char *start, char *end);

int main(void)
{
    char message[N + 1];

    printf("Enter a message: ");
    read_line(message, N);
    //printf("%s\n", message);
    reverse_message(message);
    printf("%s\n", message);

    return 0;
}


int read_line(char *message, int n)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n' && i < n)
        message[i++] = ch;
    message[i] = '\0';

    return i;
}

void reverse_message(char* message)
{
    int n = strlen(message) + 1;
    char* buffer = NULL, *buff;
    char* p = message +  n - 2;

    buffer = (char*)malloc(n);
    if (buffer == NULL)
        printf("Memory allocation failed!\n");

    buff = buffer;
    while (n-- >= 0)
       *buffer++ = *p--;
    *(buffer++) = '\0';

    strcpy(message, buff);
    free(buff);
}

/*void reverse_message(char* message)
{
   for (int i = 0, n = strlen(message); i < n/2; i++)
   {
       char temp = message[i];
       message[i] = message[n-1-i];
       message[n-1-i] = temp;
   }
}*/