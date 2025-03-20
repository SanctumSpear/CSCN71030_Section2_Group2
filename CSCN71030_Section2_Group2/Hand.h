#pragma once

#define HAND_ARRAY_HEIGHT		2
#define HAND_ARRAY_LENGTH		12

#include "Deck.h"
#include <stdio.h>

CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT];

void deal(DECK* deck);

CARD drawPlayer(DECK* deck);

CARD drawDealer(DECK* deck);

void clearHand();

void printHand();

int addDealer();

int addPlayer();