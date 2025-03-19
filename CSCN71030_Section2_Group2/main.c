#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

int main(void) {
	DECK mainDeck = createDeck();

	char buffer[64] = "0";
	char start[] = "Start";
	do {
		printf("Welcome to fortnite peter. To begin, type 'Start' \n");
	} while (scanf_s("%63s", buffer, (unsigned int)sizeof(buffer)) != 1 || strcmp(start, buffer) != 0);
	
	StartPlayerTurn();
	
	char choice = 'n';
	bool playerTurnActive = true;

	printf("This is epic blackjack, type 'h' to Hit or type 's' to Stand \n");
	while (playerTurnActive && scanf_s(" %c", &choice, (unsigned int)sizeof(choice))) {
		printf("The dealer has: \n"); //TODO: print the dealer's hand (each card) and the total value, but only the first card
		printf("You have: \n"); //TODO: print the player's hand (each card) and the total value	

		switch (choice) {
		case 'h':
			PlayerHit();
			break;
		case 's':
			EndPlayerTurn();
			playerTurnActive = false;
			break;
		default:
			printf("Invalid choice\n");
		}
	}
	StartDealerTurn();

	//do some scheisse from game state manager
}