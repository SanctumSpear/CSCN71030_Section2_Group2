#pragma once

#define HAND_ARRAY_HEIGHT		2
#define HAND_ARRAY_LENGTH		12

#include "Deck.h"
#include <stdio.h>

CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT];

void deal(DECK* deck, CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]);

void addCard(CARD card, CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]);

void printHand(CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]);

