#include "Hand.h"

void deal(DECK* deck, CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]) {
	hand[0][1] = drawCard(deck);
	hand[0][0] = drawCard(deck);
	hand[1][1] = drawCard(deck);
	hand[1][0] = drawCard(deck);
}

void addCard(CARD card, CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]) {

	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		
	}
}

void printHand(CARD hand[HAND_ARRAY_LENGTH][HAND_ARRAY_HEIGHT]) {

}