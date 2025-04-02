#include "Player.h"
#include "Deck.h"
#include "Hand.h"


#include <stdbool.h>

bool playerTurnActive = false;

void StartPlayerTurn(DECK* mainDeck) {
	deal(mainDeck);
	playerTurnActive = true;
	printf("\nYou have been dealt a ");
	printCard(hand[0][1]);
	printf(" and a ");
	printCard(hand[1][1]);
	printf("\n");

	printf("Your current hand value is %d\n\n", addPlayer());

	printf("The dealers first dealt card is: ");
	printCard(hand[0][0]);
	printf("\n\n");
}

void PlayerHit(DECK* mainDeck) {
	CARD drawn = drawPlayer(mainDeck);
	printf("You drew a ");
	printCard(drawn);
	printf("\n");
}

void EndPlayerTurn() {
	playerTurnActive = false;
}

bool IsPlayerTurnActive() {
	return playerTurnActive;
}