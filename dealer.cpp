#include "dealer.h"


Dealer::Dealer() {
	bettingMoney = 0;
	playerInProgress = 0;
	turn = 0;
	card[0] = new Card(CardColor::RED);
	card[1] = new Card(CardColor::BLACK);
	card[0]->shuffleCard();
	card[1]->shuffleCard();
}
void Dealer::setPlayer(string playerName, int playerPosition) {
	player[playerPosition] = new Player(playerName);
}
void Dealer::giveCardToPlayer() {
	player[PlayerPosition::LEFTPLAYER]->setPlayerCardNumber(card[PlayerPosition::LEFTPLAYER]->getCard(turn));
	player[PlayerPosition::RIGHTPLAYER]->setPlayerCardNumber(card[PlayerPosition::RIGHTPLAYER]->getCard(turn));
}
CurrentPlayerCardSet Dealer::getCurrentCardNumber() {
	CurrentPlayerCardSet currentCardSet;
	currentCardSet.leftPlayerCard = player[PlayerPosition::LEFTPLAYER]->getPlayerCardNumber();
	currentCardSet.rightPlayerCard = player[PlayerPosition::RIGHTPLAYER]->getPlayerCardNumber();
	return currentCardSet;
}
void Dealer::receiveToBettingMoney() {
	bettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBasicBettingMoneyToDealer();
	bettingMoney += player[PlayerPosition::RIGHTPLAYER]->giveBasicBettingMoneyToDealer();
}
void Dealer::BettingStart() {
	int leftPlayerBettingMoney = 0;
	int rightPlayerBettingMoney = 0;
	int remainingMoney = 0;
	bool giveUp = false;

	GamePageInfo gamePageInfo;
	gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
	gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
	gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
	gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
	gamePageInfo.currentAllBettingMoney = bettingMoney;
	gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);

	gamePagePlayerInfoInsertUI(gamePageInfo);

	do {
		int moneyBuffer = 0;
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			moneyBuffer = leftPlayerBettingMoney;
			gotoxy(10,25);
			leftPlayerBettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer(remainingMoney);
			if (leftPlayerBettingMoney == moneyBuffer) {
				giveUp = true;
				break;
			}
			playerInProgress = PlayerPosition::RIGHTPLAYER;
			remainingMoney = leftPlayerBettingMoney - rightPlayerBettingMoney;
			}
		else {
			moneyBuffer = rightPlayerBettingMoney;
			gotoxy(100, 25);
			rightPlayerBettingMoney += player[PlayerPosition::RIGHTPLAYER]->giveBettingMoneyToDealer(remainingMoney);
			if (rightPlayerBettingMoney == moneyBuffer) {
				giveUp = true;
				break;
			}
			playerInProgress = PlayerPosition::LEFTPLAYER;
			remainingMoney = leftPlayerBettingMoney - rightPlayerBettingMoney;
		}
		////////////여기서부터 시작 하면 될듯 월요일에
		gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
		gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
		gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
		gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
		gamePageInfo.currentAllBettingMoney = bettingMoney;
		gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);

		system("cls");
		gamePageBettingUI();
		gamePagePlayerUI();
		gamePagePlayerInfoInsertUI(gamePageInfo);
		} while (leftPlayerBettingMoney != rightPlayerBettingMoney);

	if (giveUp == true) {
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			bettingMoney += leftPlayerBettingMoney * 2;
		}
		else {
			bettingMoney += rightPlayerBettingMoney * 2;
		}
		checkWinner(giveUp);
	}
	else {
		bettingMoney += leftPlayerBettingMoney * 2;
		checkWinner(giveUp);
	}
	return;
}
void Dealer::checkWinner(bool giveUp) {
	if (giveUp == true) {
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			player[1]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
		else {
			player[0]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
	}
	else {
		if (player[0]->getPlayerCardNumber() > player[1]->getPlayerCardNumber()) {
			player[1]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::RIGHTPLAYER;
		}
		else if (player[0]->getPlayerCardNumber() < player[1]->getPlayerCardNumber()) {
			player[0]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::LEFTPLAYER;
		}
		else {
			//드로우
		}
	}
}
bool Dealer::turnCheck() {
	turn += 1;
	if (turn == 10) {
		return true;
	}
	else {
		return false;
	}
}
