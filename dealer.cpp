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

	system("cls");
	GamePageInfo gamePageInfo;
	gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
	gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
	gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
	gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
	gamePageInfo.currentAllBettingMoney = bettingMoney;
	gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);
	
	CurrentPlayerCardSet currentCardSet;

	currentCardSet.leftPlayerCard = player[0]->getPlayerCardNumber();
	currentCardSet.rightPlayerCard = player[1]->getPlayerCardNumber();
	gamePageCardUI(currentCardSet.leftPlayerCard, RED);
	gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);
	
	gamePageBettingUI();
	gamePagePlayerUI(player[0]->getPlayerName(),player[1]->getPlayerName());
	gamePagePlayerInfoInsertUI(gamePageInfo);
	gamePageGameTipUI();
	do {
		int moneyBuffer = 0;
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			moneyBuffer = leftPlayerBettingMoney;
			gotoxy(10,25);
			leftPlayerBettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer(remainingMoney, player[1]->getPlayerMoney());
			if (leftPlayerBettingMoney == moneyBuffer) {
				if (player[0]->getPlayerMoney() == 0 || player[1]->getPlayerMoney() == 0) {
					break;
				}
				else {
					giveUp = true;
					break;
				}
			}
			playerInProgress = PlayerPosition::RIGHTPLAYER;
			remainingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);
			bettingMoney += leftPlayerBettingMoney-moneyBuffer;
			}
		else {
			moneyBuffer = rightPlayerBettingMoney;
			gotoxy(100, 25);
			rightPlayerBettingMoney += player[PlayerPosition::RIGHTPLAYER]->giveBettingMoneyToDealer(remainingMoney, player[0]->getPlayerMoney());
			if (rightPlayerBettingMoney == moneyBuffer) {
				if (player[0]->getPlayerMoney() == 0 || player[1]->getPlayerMoney() == 0) {
					break;
				}
				else {
					giveUp = true;
					break;
				}
			}
			playerInProgress = PlayerPosition::LEFTPLAYER;
			remainingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);
			bettingMoney += rightPlayerBettingMoney-moneyBuffer;
		}
		////////////���⼭���� ���� �ϸ� �ɵ� �����Ͽ�
		gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
		gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
		gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
		gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
		gamePageInfo.currentAllBettingMoney = bettingMoney;
		gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);

		system("cls");
		gamePageCardUI(currentCardSet.leftPlayerCard, RED);
		gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);
		gamePageBettingUI();
		gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
		gamePagePlayerInfoInsertUI(gamePageInfo);
		gamePageGameTipUI();
		} while (leftPlayerBettingMoney != rightPlayerBettingMoney);

	checkWinner(giveUp);
	return;
}
void Dealer::checkWinner(bool giveUp) {
	if (giveUp == true) {
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			if (player[0]->getPlayerCardNumber() == 9) {
				bettingMoney += player[0]->givePenaltyMoney();
			}
			player[1]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
		else {
			if (player[1]->getPlayerCardNumber() == 9) {
				bettingMoney += player[1]->givePenaltyMoney();
			}
			player[0]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
	}
	else {
		if (player[0]->getPlayerCardNumber() < player[1]->getPlayerCardNumber()) {
			player[1]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::RIGHTPLAYER;
		}
		else if (player[0]->getPlayerCardNumber() > player[1]->getPlayerCardNumber()) {
			player[0]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::LEFTPLAYER;
		}
		else {
			bettingMoney -= player[0]->receiveDrawMoney();
			bettingMoney -= player[1]->receiveDrawMoney();
		}
	}
}
bool Dealer::turnCheck() {
	if ((player[0]->getPlayerMoney() <= 100000)||(player[1]->getPlayerMoney() <= 100000)) {
		return false;
	}
	else {
		turn += 1;
		return true;
	}
}

string Dealer::winnerSelect() {
	if (player[0]->getPlayerMoney() > player[1]->getPlayerMoney()) {
		return player[0]->getPlayerName();
	}
	else if (player[0]->getPlayerMoney() < player[1]->getPlayerMoney()) {
		return player[1]->getPlayerName();
	}
	else {
		return "";
	}
}

void Dealer::engPageUI() {

	int leftPlayerBettingMoney = 0;
	int rightPlayerBettingMoney = 0;
	int remainingMoney = 0;

	GamePageInfo gamePageInfo;
	gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
	gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
	gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
	gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
	gamePageInfo.currentAllBettingMoney = bettingMoney;
	gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);
	
	gamePageCardUI(9, RED);
	gamePageCardUI(9, BLACK);

	gamePageBettingUI();
	gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
	gamePagePlayerInfoInsertUI(gamePageInfo);
}
