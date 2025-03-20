#include "Dealer.h"
#include "Hand.h"

#include <stdbool.h>

bool dealerTurnActive = false;

void StartDealerTurn(DECK* mainDeck) {
	printf("The dealers second dealt card is: ");
	printCard(hand[1][1]);
	printf("\n\n");
	dealerTurnActive = true;
	while (addDealer < addPlayer && addDealer < 21) {
		DealerHit(mainDeck);
	}
}

void DealerHit(DECK* mainDeck) {
	drawDealer(mainDeck);
}

void EndDealerTurn() {
	dealerTurnActive = false;
}

bool IsDealerTurn() {
	return dealerTurnActive;
}