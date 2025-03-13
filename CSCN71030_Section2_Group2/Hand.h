#pragma once

#define HAND_ARRAY_HEIGHT		2
#define HAND_ARRAY_LENGTH		12

#include "Deck.h"

CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT];

void deal(DECK* deck);

void addCard(CARD card);

void printHand(CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]);