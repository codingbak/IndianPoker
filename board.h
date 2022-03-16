#pragma once

#include "server.h"
#include "client.h"
#include "dealer.h"
#include "consoleBackGround.h"


enum Page {
	MENU = 1,
	COMMUNICATIONS = 2,
	WRITE_NAME = 3,
	START_GAME = 4,
	END_GAME = 5
};
enum Communications {
	SINGLE = 0,
	SERVER = 1,
	CLIENT = 2
};


class Board {

private:
	int pageNumber;
	Server* server;
	Client* client;
	Dealer dealer;
	int communicaionsState;

public:
	Board();
	void startGame();
	void openMenuPage();
	void openCommunicationsPage();
	void openWriteNamePage();
	void openStartGamePage();
	void openEndGamePage();
};

