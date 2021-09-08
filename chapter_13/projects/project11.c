/* Finds the average word length */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 60

double compute_average_word_length(const char *sentence);
int read_line(char *sentence, int n);

int main(void)
{
    char sentence[SIZE + 1];
    double average_length;

    printf("Enter a sentence: ");
    read_line(sentence, SIZE);
    
    average_length = compute_average_word_length(sentence);
    printf("Average word length: %.2f\n", average_length);

    return 0;
}

int read_line(char *sentence, int n)
{
    int ch, i;

    i = 0;
    while((ch = getchar()) != '\n')
        if (i < n)
            sentence[i++] = ch;
    sentence[i] = '\0';

    return i;
}

double compute_average_word_length(const char *sentence)
{
    int words, letters;

    words = 1, letters = 0;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ')
            words++;
        else
            letters++;
    }

    return ( (double) letters / (double) words );
}