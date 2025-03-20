#pragma once
#include <stdbool.h>
#include "Deck.h"

void StartPlayerTurn(DECK* mainDeck);

void PlayerHit(DECK* mainDeck);

void EndPlayerTurn();

bool IsPlayerTurnActive();

