/* Checks whether a sentence is a palindrome */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 50

char* insert(char* arr);
char* reverse(char* arr, char* rev, char* ptr_ins);
bool compare(char* arr, char* rev, char* ptr_ins, char* ptr_rev);

int main(void)
{
    char arr[N];
    char rev[N];

    printf("Enter a message: ");
    /* Save the message in first array */
    char* ptr_ins = insert(arr);
    /* Put the reversed elements in another array */
    char* ptr_rev = reverse(arr, rev, ptr_ins);
    /* Checks if it's a palindrome */
    printf("%p\n", ptr_rev);

    bool palindrome = compare(arr, rev, ptr_ins, ptr_rev);

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}


/* insert: gets `arr` and inserts the letters *
**         entered by the user into `arr`.    *
**         Returns `ptr_ins` which is a point-*
**         er to the last element in the `arr`*
*/
char* insert(char* arr){
    char c;
    char* ptr_ins = arr;

    while ((c = getchar()) != '\n' && ptr_ins < arr + N)
    {
        if (c >= 'A' && c <= 'z')
            *ptr_ins++ = tolower(c);
    }
    char* k = ptr_ins--;
    printf("%p\n", ptr_ins);

    while (k >= arr)
    {
        putchar(*k--);
    }putchar('\n');

    return ptr_ins;
}

/* reverse: gets `arr` and stores its elements *
**          in reverse order by using `ptr_ins`*
**          which points to the the last elmnt *
**          of `arr` and decrements until the  *
**          first element is reached.          *
**          returns a pointer to the last ele- *
**          ment in `rev` which holds the rev- *
**          ersed elements                     *
*/
char* reverse(char* arr, char* rev, char* ptr_ins)
{
    char* ptr_rev = rev;

    printf("%p\n", ptr_ins);
    while (ptr_ins >= arr)
    {
        *ptr_rev = *ptr_ins--;
        ptr_rev++;
    }

    printf("%p\n", ptr_rev);
    
    /* why does it work?? */
    char* k = ptr_rev--;

    while (k >= rev)
    {
        putchar(*k--);
    }putchar('\n');
    return ptr_rev--;
}

/* compare: checks `arr` and `rev` if all its *
**          elements are the same and return  *
**          returns false otherwise.          *
*/
bool compare(char* arr, char* rev, char* ptr_ins, char* ptr_rev)
{
    while (ptr_ins >= arr)
    {
        putchar(*ptr_ins);
        putchar(':');
        putchar(*ptr_rev);
        putchar('\n');
        if (*ptr_ins != *ptr_rev)
            return false;
        ptr_ins --;
        ptr_rev --;
    }
    putchar('\n');

    return true;
}