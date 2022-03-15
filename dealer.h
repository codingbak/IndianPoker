#pragma once
#include "server.h"
#include "client.h"
#include <string>
#include "card.h"
#include "player.h"
#include "consoleBackGround.h"
#include <stdlib.h>

using namespace std;



enum PlayerPosition {

	LEFTPLAYER = 0,
	RIGHTPLAYER = 1
};


struct CurrentPlayerCardSet {

	int leftPlayerCard;
	int rightPlayerCard;
};


class Dealer {

private:
	int bettingMoney;
	int abstentionBettingMoney;
	int playerInProgress;
	int turn;
	Card* card[2];
	Player* player[2];


public:
	Dealer();
	void setPlayer(string playerName, int playerPosition);
	void giveCardToPlayer();
	CurrentPlayerCardSet getCurrentCardNumber();
	void receiveToBettingMoney();
	void BettingStart();
	void ServerBettingStart(Server* server);
	void ClientBettingStart(Client* client);
	void checkWinner(bool giveUp);
	bool turnCheck();
	string winnerSelect();
	void engPageUI();
};

