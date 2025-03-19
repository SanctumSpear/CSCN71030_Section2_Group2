#include "Dealer.h"
#include "Hand.h"

#include <stdbool.h>

bool firstDealerTurn = true;

void StartDealerTurn() {
	if (firstDealerTurn) {
		printf("The dealers second dealt card is: ");
		printCard(hand[1][1]);
		printf("\n\n");
		firstDealerTurn = false;
	}
}

void DealerHit() {

}

void EndDealerTurn() {

}