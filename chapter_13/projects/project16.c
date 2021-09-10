/* prints a text in reverse order */

#include <stdio.h>
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
    printf("%s\n", message);
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
   for (int i = 0, n = strlen(message); i < n/2; i++)
   {
       //swap_pos(&message[i], &message[N-i-1]);
       char temp = message[i];
       message[i] = message[n-1-i];
       message[n-1-i] = temp;
   }
}

/*void swap_pos(char *start, char *end)
{
    char temp = *start;
    *start = *end;
    *end = temp;
    printf("%c %c \n", *start, *end);
}*/