#include "board.h"

Board::Board() {
	pageNumber = Page::MENU;
}
void Board::startGame() {
	switch (pageNumber)
	{
	case Page::MENU:
		this->openMenuPage();
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
	cout << "��";

	while (1) {
		Pointer newPointer = menuCursor.cursorMove();
		bool checkNextPage = menuCursor.cursorClick();
		if (newPointer.y != nowPointer.y) {
			gotoxy(newPointer);
			cout << "��";
			indianPokerLogo();
			menuPageUI();
			nowPointer.x = newPointer.x;
			nowPointer.y = newPointer.y;
		}
		if (checkNextPage == true) {
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
	namePageUI();

	Pointer nowPointer = { 68,22 };
	string playerName;

	gotoxy(nowPointer);
	cin >> playerName;
	dealer.setPlayer(playerName, PlayerPosition::LEFTPLAYER);

	nowPointer.y += 2;
	gotoxy(nowPointer);
	cin >> playerName;
	dealer.setPlayer(playerName, PlayerPosition::RIGHTPLAYER);

	pageNumber = Page::START_GAME;
	system("cls");
	this->startGame();
	return;
}
void Board::openStartGamePage() {
	bool winnerCheck = true;
	for (int i = 0; i < 10; i++) { 
		dealer.giveCardToPlayer();
		dealer.receiveToBettingMoney();
		dealer.BettingStart();
		winnerCheck = dealer.turnCheck();
		if (winnerCheck == false) {
			break;
		}
	}
	pageNumber = Page::END_GAME;
	system("cls");
	this -> startGame();
	return;
}
void Board::openEndGamePage() {
	cout << dealer.winnerSelect();
	return;
}

