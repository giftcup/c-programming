/* Checks if a sentence is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

bool palindrome(char* arr);

int main(void)
{
    char arr[N];

    printf("Enter a message: ");
    bool pal = palindrome(arr);

    if (pal)
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    return 0;
}

bool palindrome(char* arr)
{
    int i = 0;
    char ch;

    while ((ch = getchar()) != '\n' && i <  N)
    {
        if(isalpha(ch))
            arr[i++] = tolower(ch);
    }
    
    int j = 0;
    while (j < i/2)
    {
        if (arr[j] != arr[i-j-1])
            return false;
        j++;
    }
    return true;
}