#pragma once

#include <stdbool.h>

bool writeChipsFile(int chips, char* filename);

int readChipsFile(char* filename);

int makeBet(int stock);

int betLoss(int bet);

int betWon(int bet);

bool returnBet(int bet, int stock, char* filename);