#pragma once
#include <string>
#include <iostream>


using namespace std;



class Player {

private:
	string playerName;
	int playerMoney;
	int playerCardNumber;


public:
	Player();
	Player(string playerName);

	string getPlayerName();

	void setPlayerCardNumber(int cardNumber);
	int getPlayerCardNumber();

	int giveBasicBettingMoneyToDealer();
	int giveBettingMoneyToDealer(int remainingMoney,int enemyPlayerMoney);
	int getPlayerMoney();
	void receiveVictoryMoney(int victoryMoney);
	int receiveDrawMoney();
	int givePenaltyMoney();
};

