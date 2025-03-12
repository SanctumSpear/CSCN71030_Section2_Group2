#pragma once
#include "Card.h"

#define DECK_SIZE	52
#define INITIAL_MAX_POSTION		51

typedef struct deck {
	int maxPosition;
	CARD cards[DECK_SIZE];
} DECK;

DECK createDeck();

CARD drawCard(DECK* deck);

void printDeck(DECK deck);
