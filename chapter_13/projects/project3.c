/* Deals a random hand of cards */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4 //type of card
#define NUM_RANKS 13 //number on card

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *rank_code[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
                                "Nine", "Ten", "Jack", "Queen", "King","Ace"};
    const char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};

    srand((unsigned) time(NULL));       /* generates new set of numbers each time program is run */

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:\n");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;      /* picks a random suit */
        rank = rand() % NUM_RANKS;      /* picks a random rank */
        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}