#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

int main(void) {
	srand(time(NULL));

	DECK mainDeck = createDeck();

	char buffer[64] = "0";
	char start[] = "Start";
	do {
		printf("Welcome to fortnite peter. To begin, type 'Start' \n");
	} while (scanf_s("%63s", buffer, (unsigned int)sizeof(buffer)) != 1 || strcmp(start, buffer) != 0);
	
	StartPlayerTurn(&mainDeck);
	
	char choice = 'n';

	printf("This is epic blackjack, type 'h' to Hit or type 's' to Stand \n");
	while (IsPlayerTurnActive() && scanf_s(" %c", &choice, (unsigned int)sizeof(choice))) {
		printf("The dealer has: \n"); //TODO: print the dealer's hand (each card) and the total value, but only the first card
		printf("You have: \n"); //TODO: print the player's hand (each card) and the total value	

		switch (choice) {
		case 'h':
			PlayerHit(mainDeck);
			break;
		case 's':
			EndPlayerTurn();
			break;
		default:
			printf("Invalid choice\n");
		}
	}
	StartDealerTurn();

	//do some scheisse from game state manager
}