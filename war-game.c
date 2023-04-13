#include "war-game.h"

/* ================================================================ */

void show_card(int card) {
    /* Prints the card in the form of 'TH' (Ten of Hearts), for example */
    printf("%c%c", VALUES[rank(card)], SUITS[suit(card)]);

    return ;
}

/* ================================================================ */

void shuffle_deck(int* deck, size_t n) {
    /* Randomizes an array */
    int temp;

    if (n > 1) {
        for (size_t i = 0, j; i < n; i++) {
            /* Generate a random number */
            j = i + rand() / (RAND_MAX / (n - i) + 1);

            temp = deck[j];

            deck[j] = deck[i];
            deck[i] = temp;
        }
    }

    return ;
}

/* ================================================================ */

void clear_war_deck(Queue* war_deck /* source */, Queue* hand /* destination */) {
    /* Simply a merge operation on two queues */
    int card;

    if (war_deck != NULL && hand != NULL) {
        while (war_deck->size > 0) {
            Queue_enqueue(hand, Queue_dequeue(war_deck));
        }
    }

    return ;
}

/* ================================================================ */

void show_hand(Queue* q) {
    /* Displaying content of a queue assuming it contains int */
    Node* temp = NULL;

    if (q != NULL) {
        printf("[");
        for (temp = q->head; temp != NULL; temp = temp->next) {
            show_card(*((int*) temp->data));

            if (temp->next != NULL) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return ;
}

/* ================================================================ */

void play(Queue* hand1, Queue* hand2) {
    size_t steps = 0;

    Queue* war_deck = Queue_new(NULL);
    Queue* winner = NULL;

    /* Player 1 card information */
    void* player1_top_card;
    int player1_card_value;

    /* Player 2 card information */
    void* player2_top_card;
    int player2_card_value;

    if (hand1 != NULL && hand2 != NULL) {
        while ((hand1->size != 0) && (hand2->size != 0)) {
            steps++;

            /* Player 1 reveals the top card of his deck */
            player1_top_card = Queue_dequeue(hand1);
            player1_card_value = rank(*((int*) player1_top_card));
            
            /* Player 2 reveals the top card of his deck */
            player2_top_card = Queue_dequeue(hand2);
            player2_card_value = rank(*((int*) player2_top_card));

            /* Add those two cards into the war deck */
            /* 
                ! In which order should cards be placed in a deck?
            */
            Queue_enqueue(war_deck, player1_top_card);
            Queue_enqueue(war_deck, player2_top_card);

            if (player1_card_value > player2_card_value) {
                winner = hand1;
            }
            else if (player2_card_value > player1_card_value) {
                winner = hand2;
            }
            else {
                Queue_enqueue(war_deck, Queue_dequeue(hand1));
                Queue_enqueue(war_deck, Queue_dequeue(hand2));

                if (Queue_size(hand1) == 0) {
                    printf("Player 1 ran out of cards in the war...\n");

                    winner = hand2;
                }
                else if (Queue_size(hand2) == 0) {
                    winner = hand1;
                }

                if (Queue_size(hand1) == 0 || Queue_size(hand2) == 0) {
                    clear_war_deck(war_deck, winner);
                }

                continue ;
            }

            clear_war_deck(war_deck, winner);

            if (steps > MAX_STEPS) {
                printf("Finishing the game after %d steps\n", MAX_STEPS);

                break ;
            }
        }
    }

    if (Queue_size(hand1) == DECK_SIZE) {
        printf("Player 1 wins the game in %ld steps\n", steps);
    }
    else if (Queue_size(hand2) == DECK_SIZE) {
        printf("Player 2 wins the game in %ld steps\n", steps);
    }

    Queue_destroy(&war_deck);

    return ;
}