#ifndef WAR_GAME_H
#define WAR_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "queue-ADT/queue.h"

#define VALUES "23456789TJQKA"
#define SUITS "CDHS"

/* Number of cards in a deck */
#define DECK_SIZE 52
/* Maximum number of steps */
#define MAX_STEPS 5000
/* Number of games */
#define N_GAMES 1000

/* Exceeded the number of MAX_STEPS */
#define TIE 0
/* Player 1 wins */
#define PLAYER_1 1
/* Player 2 wins */
#define PLAYER_2 2
/* Player 1 runs out of card in the war */
#define PLAYER_1_LOOSE_WAR 3
/* Player 2 runs out of card in the war */
#define PLAYER_2_LOOSE_WAR 4

/* ================================ */

/* Standard deck size */
#define DECK_SIZE 52

/* Get a value of the card */
#define rank(card) ((card % strlen(VALUES)))
/* Get a suit of the card */
#define suit(card) ((card % DECK_SIZE) / strlen(VALUES))

/* ================================================================ */

extern void show_card(int card);

extern void shuffle_deck(int* deck, size_t n);

extern void clear_war_deck(Queue* war_deck, Queue* hand);

extern void show_hand(Queue* hand);

extern int play(Queue* hand_1, Queue* hand_2);

#endif