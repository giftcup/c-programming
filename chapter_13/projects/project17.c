/* Checks if a sentence is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define N 100

bool palindrome(char* message);
int read_line(char *message, int n);

int main(void)
{
    char message[N + 1];
    bool pal;

    printf("Enter a message: ");
    read_line(message, N);
    pal = palindrome(message);

    if (pal)
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool palindrome(char* message)
{
   
    for (int i = 0, n = strlen(message); i < n/2; i++)
    {
        if (message[i] != message[n-i-1])
            return false;
    }
    return true;
}

int read_line(char *message, int n)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n' && i < n)
        if(isalpha(ch))
            message[i++] = tolower(ch);
    message[i] = '\0';

    return i;
}