/* Reverses the words in a sentence */

#include <stdio.h>
#include <string.h>

#define NUM_WORDS 30
#define WORD_LEN 20

int read_word(char *word, int n);

int main(void)
{
    char sentence[NUM_WORDS][WORD_LEN + 1];
    char word[WORD_LEN + 1];
    int  check, i = 0;

    printf("Enter a sentence: ");
    for (;;)
    {
        check = read_word(word, WORD_LEN);
        strcat(sentence[i++], word);
        if (check == 0)
            break;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%s ", sentence[j]);
    printf("\n");
    
    return 0;
}

int read_word(char *word, int n)
{
    int ch, i, check;

    i = 0;
    while ((ch = getchar()) != ' ')
    {
        if (ch == '\n')
        {
            word[i] = '\0';
            return 0;
        }
        if (i < n)
            word[i++] = ch;
    }
    word[i] = '\0';
    
    return i;
}