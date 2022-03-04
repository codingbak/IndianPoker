#include "board.h"

#define BLACK 0
#define RED 4
#define WHITE 15

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
	cout << "¢º";

	while (1) {
		Pointer newPointer = menuCursor.cursorMove();
		bool checkNextPage = menuCursor.cursorClick();
		if (newPointer.y != nowPointer.y) {
			gotoxy(newPointer);
			cout << "¢º";
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
	dealer.giveCardToPlayer();
	CurrentPlayerCardSet currentCardSet;
	currentCardSet = dealer.getCurrentCardNumber();
	gamePageCardUI(currentCardSet.leftPlayerCard, RED);
	gamePageCardUI(currentCardSet.rightPlayerCard, BLACK);
	gamePageBettingUI();
	gamePagePlayerUI();
	dealer.receiveToBettingMoney();
	dealer.BettingStart();
	return;
}
void Board::openEndGamePage() {
	return;
}

