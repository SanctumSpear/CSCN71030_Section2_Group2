#pragma once
#include <stdbool.h>

void StartPlayerTurn(DECK* mainDeck);

void PlayerHit(DECK* mainDeck);

void EndPlayerTurn();

bool IsPlayerTurnActive();

