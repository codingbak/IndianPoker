#pragma once
#include "consoleControl.h"
#include <iostream>
#include <string>
struct GamePageInfo {
	int leftPlayerMoney;
	int rightPlayerMoney;
	int leftPlayerBettingMoney;
	int rightPlayerBettingMoney;
	int currentAllBettingMoney;
	int currentCallBettingMoney;
};

void indianPokerLogo();
void menuPageUI();
void namePageUI();
void gamePageCardUI(int cardNumber, int cardColor);
void gamePageBettingUI();
void gamePagePlayerUI();
void gamePagePlayerInfoInsertUI(GamePageInfo gamePageInfo);
