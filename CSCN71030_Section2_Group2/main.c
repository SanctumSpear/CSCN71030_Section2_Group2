#include <stdio.h>
#include "Card.h"
#include "Deck.h"

int main(void) {
	//Test code for card and deck stuff

	CARD testCard = createCard(1, 1);
	printCard(testCard);
	printf_s("\n\n");

	DECK testDeck = createDeck();
	CARD deckCard = drawCard(&testDeck);
	printCard(deckCard);
	printf_s("\n\n");

	printDeck(testDeck);
	
}