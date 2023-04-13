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

extern void play(Queue* hand_1, Queue* hand_2);

#endif