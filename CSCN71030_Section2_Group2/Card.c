#include <stdio.h>
#include <string.h>
#include "Card.h"

CARD createCard(int value, int suit) {
	CARD newCard;
	newCard.value = value;
	newCard.suit = suit;

	switch (value) {
		case 1:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Ace");
			break;
		case 2:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Two");
			break;
		case 3:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Three");
			break;
		case 4:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Four");
			break;
		case 5:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Five");
			break;
		case 6:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Six");
			break;
		case 7:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Seven");
			break;
		case 8:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Eight");
			break;
		case 9:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Nince");
			break;
		case 10:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Ten");
			break;
		case 11:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Jack");
			break;
		case 12:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Queen");
			break;
		case 13:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "King");
			break;
		default:
			strcpy_s(newCard.name, MAX_NAME_SIZE, "Invalid input");
			break;
	}
	strcat_s(newCard.name, MAX_NAME_SIZE, " of ");
	switch (suit) {
		case 1:
			strcat_s(newCard.name, MAX_NAME_SIZE, "Spades");
			break;
		case 2:
			strcat_s(newCard.name, MAX_NAME_SIZE, "Clubs");
			break;
		case 3:
			strcat_s(newCard.name, MAX_NAME_SIZE, "Hearts");
			break;
		case 4:
			strcat_s(newCard.name, MAX_NAME_SIZE, "Diamonds");
			break;
		default:
			strcat_s(newCard.name, MAX_NAME_SIZE, "invalid");
			break;
	}
	
	return newCard;
}

void printCard(CARD card) {
	printf("%s", card.name);
}