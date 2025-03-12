#include "Deck.h"
#include <stdio.h>
#include <stdlib.h>

DECK createDeck() {
	DECK newDeck;
	newDeck.maxPosition = INITIAL_MAX_POSTION;

	//used to keep track of the position in the deck
	int count = 0;
	//loops through each value for each suit
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			//creats a card with the current value and suit
			newDeck.cards[count] = createCard(j, i);
			count++;
		}
	}

	return newDeck;
}

CARD drawCard(DECK* deck) {
	//generates a random position in the deck within the valid range defined by maxPosition
	srand(time(0));
	int pos = rand() % (deck->maxPosition + 1);

	//assigns the card at the random position (the drawn card) to a new card variable
	CARD card = createCard(deck->cards[pos].value, deck->cards[pos].suit);

	//shifts all the cards after the drawn card to the left
	for (int i = pos; i < INITIAL_MAX_POSTION; i++) {
		deck->cards[pos] = deck->cards[pos + 1];
	}
	//assigns the drawn card to the last position in the deck
	deck->cards[INITIAL_MAX_POSTION] = card;

	//decrements the maxPosition, reseting it back the initial value if it reaches 0
	if (deck->maxPosition != 0) {
		deck->maxPosition -= 1;
	}
	else {
		deck->maxPosition = INITIAL_MAX_POSTION;
	}

	return card;
}

//this is meant for testing purposes
void printDeck(DECK deck) {
	int count = 1;
	for (int i = 0; i < 52; i++) {
		printf_s("%d: ", count);
		printCard(deck.cards[i]);
		printf_s("\n");
		count++;
	}
}