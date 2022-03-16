#include "dealer.h"



Dealer::Dealer() {

	bettingMoney = 0;
	// 턴 확인
	playerInProgress = 0;
	// 기권할때 머니 버퍼
	abstentionBettingMoney = 0;
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

// 싱글 모드
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
	gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
	gamePagePlayerInfoInsertUI(gamePageInfo);
	gamePageGameTipUI();

	do {
		int moneyBuffer = 0;
		// 왼쪽 플레이어 턴
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			moneyBuffer = leftPlayerBettingMoney;
			gotoxy(10, 25);
			leftPlayerBettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer(remainingMoney, player[1]->getPlayerMoney());
			// 0을 냈을 경우
			if (leftPlayerBettingMoney == moneyBuffer) {

				if (player[0]->getPlayerMoney() == 0 || player[1]->getPlayerMoney() == 0) {
					break;
				}
				// 기권
				else {
					giveUp = true;
					break;
				}
			}

			playerInProgress = PlayerPosition::RIGHTPLAYER;
			remainingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);
			bettingMoney += leftPlayerBettingMoney - moneyBuffer;
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
			bettingMoney += rightPlayerBettingMoney - moneyBuffer;
		}
		////////////여기서부터 시작 하면 될듯 월요일에
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
	// 콜한 경우 턴 종료
	checkWinner(giveUp);
	return;
}

void Dealer::ServerBettingStart(Server* server) {
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
	Sleep(100);
	currentCardSet.leftPlayerCard = player[0]->getPlayerCardNumber();
	server->sendCardClient(currentCardSet.leftPlayerCard);
	Sleep(100);
	currentCardSet.rightPlayerCard = player[1]->getPlayerCardNumber();
	server->sendCardClient(currentCardSet.rightPlayerCard);
	gamePageCardUI(10, RED);
	gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);

	gamePageBettingUI();
	gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
	gamePagePlayerInfoInsertUI(gamePageInfo);
	gamePageGameTipUI();

	do {
		int moneyBuffer = 0;

		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			moneyBuffer = leftPlayerBettingMoney;
			gotoxy(10, 25);
			int sendBettingMoney = player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer(remainingMoney, player[1]->getPlayerMoney());
			leftPlayerBettingMoney += sendBettingMoney;
			if (sendBettingMoney != 0) {
				abstentionBettingMoney = sendBettingMoney;
			}
			server->sendBettingClient(sendBettingMoney);
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
			bettingMoney += leftPlayerBettingMoney - moneyBuffer;
		}

		else {
			moneyBuffer = rightPlayerBettingMoney;
			int clientBettingMoney = server->receiveBettingClient();
			gotoxy(100, 25);
			player[PlayerPosition::RIGHTPLAYER]->giveBettingMoneyToDealer(clientBettingMoney);
			rightPlayerBettingMoney += clientBettingMoney;
			if (clientBettingMoney != 0) {
				abstentionBettingMoney = clientBettingMoney;
			}
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
			bettingMoney += rightPlayerBettingMoney - moneyBuffer;
		}
		////////////여기서부터 시작 하면 될듯 월요일에
		gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
		gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
		gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
		gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
		gamePageInfo.currentAllBettingMoney = bettingMoney;
		gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);

		system("cls");
		gamePageCardUI(10, RED);
		gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);
		gamePageBettingUI();
		gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
		gamePagePlayerInfoInsertUI(gamePageInfo);
		gamePageGameTipUI();
	} while (leftPlayerBettingMoney != rightPlayerBettingMoney);

	gamePageCardUI(currentCardSet.leftPlayerCard, RED);
	gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);
	checkWinner(giveUp);

	abstentionBettingMoney = 0;

	return;
}

void Dealer::ClientBettingStart(Client* client) {
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

	currentCardSet.leftPlayerCard = client->receiveCardServer();
	player[PlayerPosition::LEFTPLAYER]->setPlayerCardNumber(currentCardSet.leftPlayerCard);
	currentCardSet.rightPlayerCard = client->receiveCardServer();
	player[PlayerPosition::RIGHTPLAYER]->setPlayerCardNumber(currentCardSet.rightPlayerCard);
	gamePageCardUI(currentCardSet.leftPlayerCard, RED);
	gamePageCardUI(10, BLACK);

	gamePageBettingUI();
	gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
	gamePagePlayerInfoInsertUI(gamePageInfo);
	gamePageGameTipUI();

	do {
		int moneyBuffer = 0;

		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			moneyBuffer = leftPlayerBettingMoney;
			int serverBettingMoney = client->receiveBettingServer();
			gotoxy(10, 25);
			player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer(serverBettingMoney);
			leftPlayerBettingMoney += serverBettingMoney;
			if (serverBettingMoney != 0) {
				abstentionBettingMoney = serverBettingMoney;
			}
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
			bettingMoney += leftPlayerBettingMoney - moneyBuffer;
		}

		else {
			moneyBuffer = rightPlayerBettingMoney;
			gotoxy(100, 25);
			int sendBettingMoney = player[PlayerPosition::RIGHTPLAYER]->giveBettingMoneyToDealer(remainingMoney, player[0]->getPlayerMoney());
			rightPlayerBettingMoney += sendBettingMoney;
			client->sendBettingServer(sendBettingMoney);
			if (sendBettingMoney != 0) {
				abstentionBettingMoney = sendBettingMoney;
			}
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
			bettingMoney += rightPlayerBettingMoney - moneyBuffer;
		}

		gamePageInfo.leftPlayerMoney = player[0]->getPlayerMoney();
		gamePageInfo.rightPlayerMoney = player[1]->getPlayerMoney();
		gamePageInfo.leftPlayerBettingMoney = leftPlayerBettingMoney;
		gamePageInfo.rightPlayerBettingMoney = rightPlayerBettingMoney;
		gamePageInfo.currentAllBettingMoney = bettingMoney;
		gamePageInfo.currentCallBettingMoney = abs(leftPlayerBettingMoney - rightPlayerBettingMoney);

		system("cls");
		gamePageCardUI(currentCardSet.leftPlayerCard, RED);
		gamePageCardUI(10, BLACK);
		gamePageBettingUI();
		gamePagePlayerUI(player[0]->getPlayerName(), player[1]->getPlayerName());
		gamePagePlayerInfoInsertUI(gamePageInfo);
		gamePageGameTipUI();
	} while (leftPlayerBettingMoney != rightPlayerBettingMoney);

	gamePageCardUI(currentCardSet.leftPlayerCard, RED);
	gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);

	checkWinner(giveUp);

	abstentionBettingMoney = 0;
	return;
}

void Dealer::checkWinner(bool giveUp) {
	//기권일 경우
	if (giveUp == true) {
		// 왼쪽 턴
		if (playerInProgress == PlayerPosition::LEFTPLAYER) {
			// 10 패널티 확인
			if (player[0]->getPlayerCardNumber() == 9) {
				bettingMoney += player[0]->givePenaltyMoney();
			}
			// 결과 보여주기 위한 처리
			if (player[0]->getPlayerCardNumber() == 9) {
				endTurnPage(1, (int)((bettingMoney - abstentionBettingMoney) - 1000000) / 2 + 1000000);
				Sleep(6000);
			}
			else {
				endTurnPage(1, (int)((bettingMoney - abstentionBettingMoney) / 2));
				Sleep(6000);
			}
			player[1]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
		else {

			if (player[1]->getPlayerCardNumber() == 9) {
				bettingMoney += player[1]->givePenaltyMoney();
			}
			if (player[1]->getPlayerCardNumber() == 9) {
				endTurnPage(0, (int)((bettingMoney - abstentionBettingMoney) - 1000000) / 2 + 1000000);
				Sleep(6000);
			}
			else {
				endTurnPage(0, (int)((bettingMoney - abstentionBettingMoney) / 2));
				Sleep(6000);
			}
			player[0]->receiveVictoryMoney(bettingMoney);
			bettingMoney = 0;
		}
	}
	// 기권이 아닌경우
	else {
		// 카드 넘버 확인 후 돈 배분
		if (player[0]->getPlayerCardNumber() < player[1]->getPlayerCardNumber()) {
			player[1]->receiveVictoryMoney(bettingMoney);
			endTurnPage(1, (int)bettingMoney / 2);
			Sleep(6000);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::RIGHTPLAYER;

		}
		else if (player[0]->getPlayerCardNumber() > player[1]->getPlayerCardNumber()) {
			player[0]->receiveVictoryMoney(bettingMoney);
			endTurnPage(0, (int)bettingMoney / 2);
			Sleep(6000);
			bettingMoney = 0;
			playerInProgress = PlayerPosition::LEFTPLAYER;
		}
		else {
			Sleep(6000);
			bettingMoney -= player[0]->receiveDrawMoney();
			bettingMoney -= player[1]->receiveDrawMoney();
		}

	}
}


bool Dealer::turnCheck() {
	// 게임이 기본 베팅 금액보다 작으면 게임 종료
	if ((player[0]->getPlayerMoney() <= 100000) || (player[1]->getPlayerMoney() <= 100000)) {
		return false;
	}

	else {
		turn += 1;
		return true;
	}
}


string Dealer::winnerSelect() {
	// 가지고 있는 금액 확인
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