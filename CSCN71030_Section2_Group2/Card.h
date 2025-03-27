#pragma once

#define MAX_NAME_SIZE	50
typedef struct card {
	int value;
	int suit;
	//1 - spade
	//2 - club
	//3 - heart
	//4 - diamond
	int aceCheck;
	//0 = low ace
	//1 = high ace
	char name[MAX_NAME_SIZE];
} CARD;

CARD createCard(int value, int suit);

void printCard(CARD card);

int getValue(CARD card);

int getSuit(CARD card);

char getName(CARD card);