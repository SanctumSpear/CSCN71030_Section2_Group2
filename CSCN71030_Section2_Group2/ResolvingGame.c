#include "Player.h"
#include "Deck.h"
#include "Hand.h"
#include "ResolvingGame.h"

#include <stdbool.h>

bool overTwenty(int valueDealer, int valuePlayer) {
	if (valueDealer > 21 || valuePlayer > 21) {
		return true;
	}
	return false;
}

int endResult(int valueDealer, int valuePlayer) {
	int dealerTotal = valueDealer;
	int playerTotal = valuePlayer;

	int endResult = 0;  //1 = DRAW 2 = WIN 3 = LOSS
	if (dealerTotal > 21 && playerTotal > 21) {
		printf("DRAW");
		endResult = 1;
	}
	if (dealerTotal == playerTotal) {
		printf("DRAW");
		endResult = 1;
	}
	if (dealerTotal < 21 && playerTotal < 21 && dealerTotal <= playerTotal) {
		printf("WIN");
		endResult = 2;
	}
	if (dealerTotal > 21 && playerTotal < 21) {
		printf("WIN");
		endResult = 2;
	}
	if (dealerTotal < 21 && playerTotal < 21 && dealerTotal >= playerTotal) {
		printf("LOSS");
		endResult = 3;
	}
	if (dealerTotal < 21 && playerTotal > 21) {
		printf("LOSS");
		endResult = 3;
	}
	return endResult;
}
