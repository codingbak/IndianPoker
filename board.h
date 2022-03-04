#pragma once
#include "dealer.h"
#include "consoleBackGround.h"

enum Page {
	MENU = 1,
	WRITE_NAME = 2,
	START_GAME = 3,
	END_GAME = 4
};

class Board {
private:
	int pageNumber;
	Dealer dealer;
public:
	Board();
	void startGame();
	void openMenuPage();
	void openWriteNamePage();
	void openStartGamePage();
	void openEndGamePage();
	
};

