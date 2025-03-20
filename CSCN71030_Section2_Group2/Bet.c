#include "Bet.h"
#include <stdio.h>
#include <stdlib.h>

bool writeChipsFile(int chips, char* filename) {
	FILE* dataFile = fopen(filename, "w");
	if (dataFile == NULL) {
		fprintf(stderr, "Failed to open file\n");
		return false;
	}

	fprintf(dataFile, "%d", chips);
	fclose(dataFile);

	return true;
}

int readChipsFile(char* filename) {
	FILE* dataFile = fopen(filename, "r");
	if (dataFile == NULL) {
		fprintf(stderr, "Failed to open file\n");
		exit(EXIT_FAILURE);
	}

	int stock;

	fscanf_s(dataFile, "%d", &stock);
	fclose(dataFile);

	return stock;
}

int makeBet(int stock) {
	bool loop = true;
	do {
		printf("Make a bet: \n");

		int bet;
		scanf_s("%d\n", bet);

		if (bet > stock) {
			printf("Make sure bet is less than or equal to the amount of chips you have access to.\n");
		}
		else {
			stock = stock - bet;
			return bet;
		}
	} while (loop);
}

int betLoss(int bet) {
	int loss = bet / 2;
	return loss;
}

int betWon(int bet) {
	int won = bet * 2;
	return won;
}

bool returnBet(int bet, int stock, char* filename) {
	FILE* dataFile = fopen(filename, "w");
	if (dataFile == NULL) {
		fprintf(stderr, "Failed to open file\n");
		return false;
	}

	int newStock = bet + stock;
	fprintf(dataFile, "%d", newStock);
	fclose(dataFile);

	return true;
}