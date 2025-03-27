#include "Hand.h"

void deal(DECK* deck) {
	hand[0][1] = drawCard(deck);
	hand[0][0] = drawCard(deck);
	hand[1][1] = drawCard(deck);
	hand[1][0] = drawCard(deck);
}

CARD drawPlayer(DECK* deck) {
	CARD blank = createCard(0, 0);
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][1].value == blank.value) {
			hand[i][1] = drawCard(deck);
			return hand[i][1];
		}
	}
	return blank;
}

CARD drawDealer(DECK* deck) {
	CARD blank = createCard(0, 0);
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][0].value == blank.value) {
			hand[i][0] = drawCard(deck);
			return hand[i][0];
		}
	}
	return blank;
}

void clearHand() {
	for (int i = 0; i < HAND_ARRAY_HEIGHT; i++) {
		for (int j = 0; i < HAND_ARRAY_LENGTH; j++) {
			hand[j][i] = createCard(0, 0);
		}
	}
}

void printHand() {

}

int addDealer() {
	int valueDealer = 0;
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		valueDealer = valueDealer + hand[i][0].value;
	}
	return valueDealer;
}

int addPlayer() {
	int valuePlayer = 0;
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		valuePlayer = valuePlayer + hand[i][1].value;
	}
	return valuePlayer;
}