#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Hand.h"
#include "Bet.h"
#include "ResolvingGame.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));

	DECK mainDeck = createDeck();

	char buffer[64] = "0";
	char start[] = "Start";
	char playChoice;
	bool playAgain = true;
	char* filename = "chips.txt";
	int stock;

	do {

		do {
			printf("Welcome to blackjack. To begin, type 'Start' \n");
		} while (scanf_s("%63s", buffer, (unsigned int)sizeof(buffer)) != 1 || strcmp(start, buffer) != 0);

		int args = atoi(argv[1]);
		
		if (args == 1) {
			stock = readChipsFile(filename);
		} else {
			stock = 100;
			returnBet(0, stock, filename);
		}

		printf("How much would you like to bet?\n");
		int bet;
		bool loopBet = true;
		while (loopBet) {
			printf("Chips: %d\n", stock);
			scanf_s("%d", &bet);

			if (bet <= stock) {
				printf("You bet %d chips\n", bet);
				stock = stock - bet;
				loopBet = false;
			}
			else if (bet < 0) {
				printf("Please enter a positive integer.\n");
			}
			else {
				printf("Please enter a bet that is lower than the amount of chips you have access to.\n");
			}
		}
	

		StartPlayerTurn(&mainDeck);

		char choice = 'n';
		while (getchar() != '\n');
	
		printf("This is epic blackjack, type 'h' to Hit or type 's' to Stand \n");
		while (IsPlayerTurnActive() && scanf_s(" %c", &choice, (unsigned int)sizeof(choice))) {
			if (overTwenty(addDealer(), addPlayer())) {
				EndPlayerTurn();
				break;
			}
			switch (choice) {
			case 'h':
				PlayerHit(&mainDeck);
				break;
			case 's':
				EndPlayerTurn();
				break;
			default:
				printf("Invalid choice\n");
			}
			printf("The dealer has: %d\n", hand[0][0].value);
			printf("You have: %d\n", addPlayer());
			if (overTwenty(addDealer(), addPlayer())) {
				EndPlayerTurn();
			}
		}	

		if (addPlayer() <= 21) {
			StartDealerTurn(&mainDeck);
		}

		if (!IsDealerTurnActive() && !IsPlayerTurnActive()) {
			int result = endResult(addDealer(),addPlayer());
			if (result == 1) {
				returnBet(bet, stock, filename);
			}
			else if (result == 2) {
				int wBet = betWon(bet);
				returnBet(wBet, stock, filename);
			}
			else if (result == 3) {
				int lBet = betLoss(bet);
				returnBet(lBet, stock, filename);
			}
		}


		printf("\nEnter any key to keep playing, or enter 'x' to exit\n");
		scanf_s(" %c", &playChoice, (unsigned int)sizeof(playChoice));
		if (playChoice == 'x') {
			playAgain = false;
		}
		clearHand();
	} while (playAgain);
}