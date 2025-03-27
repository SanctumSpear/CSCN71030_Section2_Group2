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
		for (int j = 0; j < HAND_ARRAY_LENGTH; j++) {
			hand[j][i] = createCard(0, 0);
		}
	}
}

void printHand() {

}

int addDealer() {
	int valueDealer = 0;
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][0].value == 11 || hand[i][0].value == 12 || hand[i][0].value == 13) {
			valueDealer = valueDealer + 10;
		}
		else {
			valueDealer = valueDealer + hand[i][0].value;
		}
	}

	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][0].value == 1 && hand[i][0].aceCheck == 0 && valueDealer + 10 <= 21) {
			hand[i][0].aceCheck = 1;
			valueDealer = valueDealer + 10;
		}
		if (hand[i][0].value == 1 && hand[i][0].aceCheck == 1 && valueDealer > 21) {
			hand[i][0].aceCheck = 0;
			valueDealer = valueDealer - 10;
		}
	}
	return valueDealer;
}

int addPlayer() {
	int valuePlayer = 0;
	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][1].value == 11 || hand[i][1].value == 12 || hand[i][1].value == 13){
			valuePlayer = valuePlayer + 10;
		}
		else {
			valuePlayer = valuePlayer + hand[i][1].value;
		}
	}

	for (int i = 0; i < HAND_ARRAY_LENGTH; i++) {
		if (hand[i][1].value == 1 && hand[i][1].aceCheck == 0 && valuePlayer + 10 <= 21) {
			hand[i][1].aceCheck = 1;
			valuePlayer = valuePlayer + 10;
		}
		if (hand[i][1].value == 1 && hand[i][1].aceCheck == 1 && valuePlayer > 21) {
			hand[i][1].aceCheck = 0;
			valuePlayer = valuePlayer - 10;
		}
	}
	return valuePlayer;
}