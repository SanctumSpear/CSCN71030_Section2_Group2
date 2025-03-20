#pragma once
#include <stdbool.h>

void StartDealerTurn();

void DealerHit(DECK * mainDeck);

void EndDealerTurn();

bool IsDealerTurn();