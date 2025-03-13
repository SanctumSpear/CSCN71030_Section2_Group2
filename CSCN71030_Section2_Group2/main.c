#include <stdio.h>
#include "Card.h"
#include "Deck.h"
#include <string.h>

int main(void) {
	//Test code for card and deck stuff

	//CARD testCard = createCard(1, 1);
	//printCard(testCard);
	//printf_s("\n\n");

	//DECK testDeck = createDeck();
	//CARD deckCard = drawCard(&testDeck);
	//printCard(deckCard);
	//printf_s("\n\n");

	//printDeck(testDeck);
	char begin[64] = "0";
	char start[] = "Start";
	do {
		printf("Welcome to fortnite peter. To begin, type 'Start' \n");
	} while ( scanf_s("%63s", begin, (unsigned int)sizeof(begin) ) != 1 || !strncmp(start, begin,6) );
	printf("%s", begin);
	
}