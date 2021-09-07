/* Calculates the points for words in a scrabble game */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compute_scrabble_value(const char *word);

int main(void)
{
    char word[12];
    int score;
    printf("Enter a word: ");
    scanf("%s", word);
    
    score = compute_scrabble_value(word);
    printf("Scrabble value: %d\n", score);
}

int compute_scrabble_value(const char *word)
{
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        char temp = toupper(word[i]);
        score += scores [temp - 'A'];
    }

    return score;
}