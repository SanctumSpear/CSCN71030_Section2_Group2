#include "Dealer.h"
#include "Hand.h"

#include <stdbool.h>

bool dealerTurnActive = false;

void StartDealerTurn(DECK* mainDeck) {
	printf("The dealers second dealt card is: ");
	printCard(hand[1][1]);
	printf("\n\n");
	printf("He now has a hand value of %d\n", addDealer());
	dealerTurnActive = true;
	while (addDealer < addPlayer && addDealer < 21) {
		DealerHit(mainDeck);
	}
}

void DealerHit(DECK* mainDeck) {
	CARD drawn = drawDealer(mainDeck);
	printf("The dealer drew an: ");
	printCard(drawn);
	printf("\nHe now has a hand value of: %d\n", addDealer());
}

void EndDealerTurn() {
	dealerTurnActive = false;
}

bool IsDealerTurn() {
	return dealerTurnActive;
}