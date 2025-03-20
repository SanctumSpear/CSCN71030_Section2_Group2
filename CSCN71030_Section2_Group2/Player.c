#include "Player.h"
#include "Deck.h"
#include "Hand.h"

#include <stdbool.h>

bool firstPlayerTurn = true;

bool playerTurnActive = false;

void StartPlayerTurn(DECK* mainDeck) {

	if (firstPlayerTurn) {
		deal(mainDeck);
		firstPlayerTurn = false;
		playerTurnActive = true;
		printf("You have been dealt: ");
		printHand();//fo player
		printf("\n");


		printf("The dealers first dealt card is: ");
		printCard(hand[0][1]);
		printf("\n\n");
	}
	
}

void PlayerHit(DECK* mainDeck) {
	draw(mainDeck);
}

void EndPlayerTurn() {
	playerTurnActive = false;
}

bool IsPlayerTurnActive() {
	return playerTurnActive;
}