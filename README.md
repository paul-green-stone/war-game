# War Game

## About

A simulation of a **war** card game.

If the two cards are of equal value, then there is a "war". Both players place the next card from their pile face down and then another card face-up.

## API

### shuffle_deck

```C
void shuffle_deck(int* deck, size_t n);
```

This function randomizes an array (deck). I copied the function from [stack overflow](https://stackoverflow.com/questions/6127503/shuffle-array-in-c). The game outcome may be affected by the way deck is randomized. Feel free to provide another implementation.

## clear_war_deck

```C
void clear_war_deck(Queue* war_deck, Queue* hand);
```

Simply a merge operation on two queues.

## void show_hand

```C
void show_hand(Queue* hand);
```

Displays the queue/deck. The function assumes the queue contains `int`.
