#pragma once
#include <stdbool.h>
#include "Deck.h"

void StartDealerTurn();

void DealerHit(DECK* mainDeck);

void EndDealerTurn();

bool IsDealerTurn();