#include "Player.h"
#include "Deck.h"
#include "Hand.h"

#include <stdbool.h>

bool overTwenty() {
	int dealerTotal = hand[0][1]; //hhhhh
	for (int i = 0; i = 21; i++) { //checks all possible cards incase possibility for larger hands is realized
		dealerTotal = dealerTotal + hand[i][1];
	}
	int playerTotal = hand[0][0]; //hhhhhhhhhh
	for (int i = 0; i = 21; i++) { 
		dealerTotal = playerTotal + hand[i][0];
	}
	if (dealerTotal > 21 || playerTotal > 21) {
		endResult();
	}
	return 0;
}

int endResult() {
	int endResult;  //1 = DRAW 2 = WIN 3 = LOSS
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