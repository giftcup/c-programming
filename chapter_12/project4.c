/* Checks if a sentence is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

int get_message(char* message);
bool palindrome(char* message, int length);

int main(void)
{
    char message[N];
    bool pal;
    int length;

    printf("Enter a message: ");
    length = get_message(message);

    pal = palindrome(message, length);

    printf("%s\n", pal ? "Palindrome" : "Not a palindrome");

    return 0;
}

int get_message(char* message)
{
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n' && i < N)
    {
        if(isalpha(ch)){
            *(message + i) = tolower(ch);
            i++;
        }
    }
    i--;
    return i;
}

bool palindrome(char* message, int length)
{
    int j = 0;
    while (j < length)
    {
        if (*(message + j) != *(message + length))
            return false;
        j ++;
        length--;
    }
    return true;
}
