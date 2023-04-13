#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "war-game.h"

/* ================================================================ */

int main(int argc, char** argv) {
    /* 'Initialize' a random number generator */
    time_t t;
    srand((unsigned) time(&t));

    /* Game deck */
    int deck[DECK_SIZE];

    /* Players' decks/hands */
    Queue* player1_hand = Queue_new(NULL);
    Queue* player2_hand = Queue_new(NULL);

    /* Create a deck */
    for (size_t i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }

    /* Shuffle the deck */
    shuffle_deck(deck, DECK_SIZE / 2);

    /* Deal */
    for (size_t i = 0; i < DECK_SIZE; i++) {
        if (i % 2 == 0) {
            Queue_enqueue(player1_hand, (void*) (deck + i));
        }
        else {
            Queue_enqueue(player2_hand, (void*) (deck + i));
        }
    }

    play(player1_hand, player2_hand);

    Queue_destroy(&player1_hand);
    Queue_destroy(&player2_hand);

    return EXIT_SUCCESS;
}