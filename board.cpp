#include "board.h"



Board::Board() {
	pageNumber = Page::MENU;
}


void Board::startGame() {
	switch (pageNumber) {

	case Page::MENU:
		this->openMenuPage();
		break;

	case Page::COMMUNICATIONS:
		this->openCommunicationsPage();
		break;

	case Page::WRITE_NAME:
		this->openWriteNamePage();
		break;

	case Page::START_GAME:
		this->openStartGamePage();
		break;

	case Page::END_GAME:
		this->openEndGamePage();
		break;
	}
}


void Board::openMenuPage() {

	indianPokerLogo();
	menuPageUI();

	Pointer nowPointer = { 48,22 };
	CursorControl menuCursor(nowPointer);

	gotoxy(nowPointer);
	cout << "▶";

	while (1) {
		Pointer newPointer = menuCursor.cursorMove();
		bool checkNextPage = menuCursor.cursorClick();

		if (newPointer.y != nowPointer.y) {
			gotoxy(newPointer);
			cout << "▶";
			indianPokerLogo();
			menuPageUI();
			nowPointer.x = newPointer.x;
			nowPointer.y = newPointer.y;
		}

		if (checkNextPage == true) {
			if (nowPointer.y == 22) {
				pageNumber = Page::COMMUNICATIONS;
				system("cls");
				this->startGame();
			}
			else {
				exit(0);
			}
			return;
		}

	}
	return;
}

void Board::openCommunicationsPage() {
	indianPokerLogo();
	communicationsPageUI();

	Pointer nowPointer = { 48,22 };
	CursorControl menuCursor(nowPointer);

	gotoxy(nowPointer);
	cout << "▶";

	while (1) {

		Pointer newPointer = menuCursor.cursorMove();
		bool checkNextPage = menuCursor.cursorClick();

		if (newPointer.y != nowPointer.y) {

			gotoxy(newPointer);
			cout << "▶";
			indianPokerLogo();
			communicationsPageUI();
			nowPointer.x = newPointer.x;
			nowPointer.y = newPointer.y;
		}

		if (checkNextPage == true) {
			if (nowPointer.y == 23) {
				communicaionsState = Communications::SERVER;
				server = new Server();

			}
			else if (nowPointer.y == 24) {
				communicaionsState = Communications::CLIENT;
				client = new Client();
			}
			else {
				Communications::SINGLE;
			}
			pageNumber = Page::WRITE_NAME;
			system("cls");
			this->startGame();
			return;


		}
	}
	return;
}


void Board::openWriteNamePage() {

	indianPokerLogo();


	Pointer nowPointer = { 68,22 };
	string playerName;

	if (communicaionsState == Communications::SINGLE) {
		namePageUI();

		gotoxy(nowPointer);
		cin >> playerName;
		dealer.setPlayer(playerName, PlayerPosition::LEFTPLAYER);

		nowPointer.y += 2;
		gotoxy(nowPointer);
		cin >> playerName;
		dealer.setPlayer(playerName, PlayerPosition::RIGHTPLAYER);
	}

	else if (communicaionsState == Communications::SERVER) {

		serverNamePageUI();

		gotoxy(nowPointer);
		cin >> playerName;

		dealer.setPlayer(playerName, PlayerPosition::LEFTPLAYER);
		server->sendNameClient(playerName);
		playerName = server->receiveNameClient();
		dealer.setPlayer(playerName, PlayerPosition::RIGHTPLAYER);
	}

	else {
		clientNamePageUI();
		playerName = client->receiveNameServer();
		dealer.setPlayer(playerName, PlayerPosition::LEFTPLAYER);
		gotoxy(nowPointer);
		cin >> playerName;
		client->sendNameServer(playerName);
		dealer.setPlayer(playerName, PlayerPosition::RIGHTPLAYER);
	}

	pageNumber = Page::START_GAME;
	system("cls");
	this->startGame();
	return;
}


void Board::openStartGamePage() {

	bool winnerCheck = true;


	if (communicaionsState == Communications::SINGLE) {

		for (int i = 0; i < 10; i++) {
			dealer.giveCardToPlayer();
			dealer.receiveToBettingMoney();
			dealer.BettingStart();
			winnerCheck = dealer.turnCheck();
			if (winnerCheck == false) {
				break;
			}
		}
	}

	else if (communicaionsState == Communications::SERVER) {
		for (int i = 0; i < 10; i++) {
			dealer.giveCardToPlayer();
			dealer.receiveToBettingMoney();
			dealer.ServerBettingStart(server);
			winnerCheck = dealer.turnCheck();
			if (winnerCheck == false) {
				break;
			}
		}
	}

	else {
		for (int i = 0; i < 10; i++) {
			dealer.receiveToBettingMoney();
			dealer.ClientBettingStart(client);
			winnerCheck = dealer.turnCheck();
			if (winnerCheck == false) {
				break;
			}
		}
	}

	pageNumber = Page::END_GAME;
	system("cls");
	this->startGame();
	return;
}
void Board::openEndGamePage() {

	dealer.engPageUI();
	endPageWinnerUI(dealer.winnerSelect());

	return;
}
