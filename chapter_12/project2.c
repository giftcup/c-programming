/* Checks whether a message is a palindrome */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 50

int insert(char arr[N]);
void reverse(char arr[N], char rev[N], int i);
bool compare(char arr[N], char rev[N], int insert_count);

int main(void)
{
    char arr[N];
    
    printf("Enter a message: ");
    int insert_count = insert(arr);
    char rev[N];
    reverse(arr, rev, insert_count);
    bool palindrome = compare(arr, rev, insert_count);
    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;  
}

int insert(char arr[N])
{
    char c;
    int i = 0;

    while ((c = getchar()) != '\n' && i < N)
    {
        if (c >= 'A' && c <= 'z')
            arr[i++] = tolower(c);
    }
    
    return i - 1;
}

void reverse(char arr[N], char rev[N], int i)
{
    int j = 0;

    while (i >= 0)
    {
        rev[j++] = arr[i--];
    }
}

bool compare(char arr[N], char rev[N], int i)
{
    while (i >= 0)
    {
        if (arr[i] != rev[i])
            return false;
        i--;
    }
    return true;
}
