/* Checks if a sentence is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

bool palindrome(char* message);

int main(void)
{
    char message[N];
    bool pal;

    printf("Enter a message: ");
    pal = palindrome(message);

    if (pal)
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool palindrome(char* message)
{
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i <  N)
    {
        if(isalpha(ch))
            message[i++] = tolower(ch);
    }
    
    int j = 0;
    while (j < i/2)
    {
        if (message[j] != message[i-j-1])
            return false;
        j++;
    }
    return true;
}