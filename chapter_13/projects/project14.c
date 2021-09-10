/* Tests whether two words are anagrams */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 20

int read_line(char *message, int n);
bool is_anagram(char *word1, char *word2);

int main(void)
{
    char word1[LEN + 1], word2[LEN + 1];
    bool anagram;

    printf("Enter first word: ");
    read_line(word1, LEN);
    printf("Enter second word: ");
    read_line(word2, LEN);

    anagram = is_anagram(word1, word2);
    if (anagram)
        printf("Words are anagrams\n");
    else
        printf("They are not anagrams\n");

    return 0;
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

bool is_anagram(char *word1, char *word2)
{
    if (strcmp(word1, word2) == 0)
        return true;
    return false;
}