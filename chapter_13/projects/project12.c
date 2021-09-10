/* Reverses the words in a sentence */

#include <stdio.h>
#include <string.h>

#define NUM_WORDS 30
#define WORD_LEN 20

int read_word(char *word, int n);

int main(void)
{
    char sentence[NUM_WORDS][WORD_LEN + 1], stop;
    int ch, i, j;

    i = 0, j = 0;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n' && i < NUM_WORDS)
    {
        if (ch == '.' || ch == '!' || ch == '?')
        {
            stop = ch;
            break;
        }
        if (ch == ' ')
        {
            sentence[i][j] = '\0';
            i++;
            j = 0;
            continue;
        }

        sentence[i][j++] = ch;
    }
    sentence[i][j] = '\0';

    for (i; i >= 0; i--)
        printf("%s ", sentence[i]);
    printf("%c\n", stop);

    return 0;
}