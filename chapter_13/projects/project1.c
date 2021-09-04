/* Finds the smallest and largest words in a series */

#include <stdio.h>
#include <string.h>

#define STOP 4
#define WORD_LEN 20

int main(void)
{
    char word[WORD_LEN + 1];
    char smallest[WORD_LEN + 1];
    char largest[WORD_LEN + 1];

    printf("Enter word: ");
    scanf("%s", word);
    strcpy(smallest, word);
    for (;;)
    {
        printf("Enter word: ");
        scanf("%s", word);

        if (strcmp(word, smallest) < 0)
            strcpy(smallest, word);
        if (strcmp(word, largest) > 0)
            strcpy(largest, word);
        
        if (strlen(word) == 4)
            break;
    }

    printf("Smallest word: %s\nLargest word: %s\n", smallest, largest);

    return 0;
}