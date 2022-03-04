#include "player.h"

#define BASIC_BET 100000


Player::Player() {

	}
Player::Player(string playerName) : playerName(playerName) {
		playerMoney = 5000000;
	}

string Player::getPlayerName() {
		return playerName;
	}

int Player::getPlayerMoney() {
	return playerMoney;
}

void Player::setPlayerCardNumber(int cardNumber) {
		this->playerCardNumber = cardNumber;
	}
int Player::getPlayerCardNumber() {
		return playerCardNumber;
	}


int Player::giveBasicBettingMoneyToDealer() {
		playerMoney -= BASIC_BET;
		return BASIC_BET;
	}

int Player::giveBettingMoneyToDealer(int remainingMoney) {
		int bettingMoney = 0;
		//try catch 입력에 대하여
		cin >> bettingMoney;
		//if else
		return bettingMoney;
	}


void Player::receiveVictoryMoney(int victoryMoney) {
		playerMoney += victoryMoney;
	}
