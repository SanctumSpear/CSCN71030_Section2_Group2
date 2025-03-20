#include "Dealer.h"
#include "Hand.h"

#include <stdbool.h>

bool firstDealerTurn = true;

bool dealerTurnActive = false;

void StartDealerTurn() {
	if (firstDealerTurn) {
		printf("The dealers second dealt card is: ");
		printCard(hand[1][1]);
		printf("\n\n");
		firstDealerTurn = false;
		dealerTurnActive = true;
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