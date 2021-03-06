/* Checks if a sentence is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

char* get_message(char* message);
bool palindrome(char* message, char* ptr);

int main(void)
{
    char message[N];
    bool pal;
    char* ptr_message;

    printf("Enter a message: ");
    ptr_message = get_message(message);

    pal = palindrome(message, ptr_message);

    printf("%s\n", pal ? "Palindrome" : "Not a palindrome");

    return 0;
}

/* get_message: Reads message from user and stores in
**              array `messsage`.
*/
char* get_message(char* message)
{
    char ch;
    char* ptr = message;

    while ((ch = getchar()) != '\n' && ptr <  message + N)
    {
        if(isalpha(ch))
            *ptr++ = tolower(ch);
    }ptr--;
    return ptr;
}

/* palindrome: Checks the characters of the message from
**              left-to-right and right-to-left if they
**              are the same.
**              returns true if the are and false other-
**              wise.
*/
bool palindrome(char* message, char* ptr)
{
     
    char* ptr2 = message;
    while (ptr2 < ptr)
    {
        if (*ptr2 != *ptr)
            return false;
        ptr2++;
        ptr--;
    }
    return true;
}
