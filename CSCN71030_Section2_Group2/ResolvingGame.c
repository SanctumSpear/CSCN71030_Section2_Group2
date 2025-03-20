#include "Player.h"
#include "Deck.h"
#include "Hand.h"
#include "ResolvingGame.h"

#include <stdbool.h>

bool overTwenty() {
	int dealerTotal = addDealer;
	int playerTotal = addPlayer;
	if (dealerTotal > 21 || playerTotal > 21) {
		endResult();
	}
	return 0;
}

int endResult() {
	int dealerTotal = addDealer;
	int playerTotal = addPlayer;

	int endResult = 0;  //1 = DRAW 2 = WIN 3 = LOSS
	if (dealerTotal > 21 && playerTotal > 21) {
		fprint("DRAW");
		endResult = 1;
	}
	if (dealerTotal == playerTotal) {
		fprint("DRAW");
		endResult = 1;
	}
	if (dealerTotal < 21 && playerTotal < 21 && dealerTotal <= playerTotal) {
		fprint("WIN");
		endResult = 2;
	}
	if (dealerTotal > 21 && playerTotal < 21) {
		fprint("WIN");
		endResult = 2;
	}
	if (dealerTotal < 21 && playerTotal < 21 && dealerTotal >= playerTotal) {
		fprint("LOSS");
		endResult = 3;
	}
	if (dealerTotal < 21 && playerTotal > 21) {
		fprint("LOSS");
		endResult = 3;
	}
	return endResult;
}
