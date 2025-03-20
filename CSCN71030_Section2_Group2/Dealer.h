#pragma once
#include <stdbool.h>
#include "Deck.h"

void StartDealerTurn(DECK* mainDeck);

void DealerHit(DECK* mainDeck);

void EndDealerTurn();

bool IsDealerTurn();