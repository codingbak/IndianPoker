#include "player.h"

#define BASIC_BET 100000
#define PENALTY_BET 1000000

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

int Player::giveBettingMoneyToDealer(int remainingMoney, int enemyPlayerMoney) {
		int bettingMoney = 0;
		int maxBettingMoney = enemyPlayerMoney + remainingMoney;
		int minBettingMoney = remainingMoney;
		cin >> bettingMoney;
		while (1) {
			if (minBettingMoney > bettingMoney) {
				cout << "call보다 적은 금액을 입력하셨습니다.";
				cin >> bettingMoney;
			}
			else if (maxBettingMoney < bettingMoney) {
				cout << "너무 높은 베팅을 입력하셨습니다.";
				cin >> bettingMoney;
			}
			else {
				break;
			}
		}
		playerMoney -= bettingMoney;
		return bettingMoney;
	}


void Player::receiveVictoryMoney(int victoryMoney) {
		playerMoney += victoryMoney;
	}

int Player::receiveDrawMoney() {
	playerMoney += BASIC_BET;
	return BASIC_BET;
}

int Player::givePenaltyMoney() {
	playerMoney -= PENALTY_BET;
	return PENALTY_BET;
}