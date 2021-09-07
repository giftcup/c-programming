/* Counts the vowels in a sentence */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SEN_LEN 60

int compute_vowel_count(const char *sentence);
int read_line(char *sentence, int n);

int main(void)
{
    char sentence[SEN_LEN + 1];
    int vowels;

    printf("Enter a sentence: ");
    read_line(sentence, SEN_LEN);
    vowels = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels\n", vowels);

    return 0;
}

int read_line(char *sentence, int n)
{
    int ch, i;

    i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            sentence[i++] = ch;
    sentence[i] = '\0';
    
    return i;
}

int compute_vowel_count(const char *sentence)
{
    int vowel_count = 0;
    
    for (int i = 0; i < strlen(sentence); i++)
    {
        int c = tolower(sentence[i]);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel_count ++;
    }
    return vowel_count;
}