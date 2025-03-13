#include "Hand.h"

void deal(DECK* deck) {
	hand[0][1] = drawCard(deck);
	hand[0][0] = drawCard(deck);
	hand[1][1] = drawCard(deck);
	hand[1][0] = drawCard(deck);
}

void draw(DECK* deck) {
	CARD blank = createCard(0, 0);
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][1].value == blank.value) {
			hand[i][1] = drawCard(deck);
		}
	}
}

void printHand() {

}