#include "Player.h"
#include "Deck.h"
#include "Hand.h"

#include <stdbool.h>

bool firstTurn = true;

void StartPlayerTurn(DECK* mainDeck) {

	if (firstTurn) {
		deal(mainDeck);
		firstTurn = false;
	}
	
}

void PlayerHit() {

}

void EndPlayerTurn() {

}