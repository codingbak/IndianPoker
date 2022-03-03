#include <algorithm>
#include <string>
#include "consoleBackGround.h"


#define PAGE_COUNT 4
#define BASIC_BET 100000


using namespace std;
enum PlayerPosition {
	LEFTPLAYER = 0,
	RIGHTPLAYER = 1
};

enum CardColor {
	RED = 0,
	BLACK = 1
};

enum Page {
	MENU = 1,
	WRITE_NAME = 2,
	START_GAME = 3,
	END_GAME =4
};

class Card
{
	private:
		int cardNumber[10];
		CardColor cardColor;

	public:
		Card(CardColor color)
		{
			cardColor = color;
			for (int i = 0; i < 10; i++) {
				cardNumber[i] = i;
			}
		}
		void shuffleCard()
		{	
			srand((unsigned int)time(NULL));
			for (int i = 0; i < 10; i++) {
				int randomNumber = rand();
				swap(cardNumber[i], cardNumber[(int)randomNumber % 10]);
			}
		}
		int getCard(int turn) {
			return cardNumber[turn];
		}
};
class Dealer
{
	private:
		int bettingMoney;
		int PlayerInProgress;
		int turn;
		Card *card[2];
		Player *player[2];
	public:
		Dealer() {
			bettingMoney = 0;
			PlayerInProgress=0;
			turn = 0;
			card[0] = new Card(CardColor::RED);
			card[1] = new Card(CardColor::BLACK);
			card[0]->shuffleCard();
			card[1]->shuffleCard();
		}
		void setPlayer(string playerName, int playerPosition ) {
			player[playerPosition] = new Player(playerName);
		}
		void giveCardToPlayer() {
			
			player[PlayerPosition::LEFTPLAYER]->setPlayerCardNumber(card[PlayerPosition::LEFTPLAYER]->getCard(turn));
			player[PlayerPosition::RIGHTPLAYER]->setPlayerCardNumber(card[PlayerPosition::RIGHTPLAYER]->getCard(turn));

		}
		void receiveToBettingMoney() {
			bettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBasicBettingMoneyToDealer();
			bettingMoney += player[PlayerPosition::RIGHTPLAYER]->giveBasicBettingMoneyToDealer();
		}
		void BettingStart() {
			
			int leftPlayerBettingMoney = 0;
			int rightPlayerBettingMoney = 0;
			int remainingMoney = 0;
			bool giveUp = false;
			if (PlayerInProgress == PlayerPosition::LEFTPLAYER) {
				leftPlayerBettingMoney += player[PlayerPosition::LEFTPLAYER]->giveBettingMoneyToDealer();
				if (leftPlayerBettingMoney == 0) {
					giveUp = true;
					checkWinner(giveUp);
				}
				else {
					
				}
			}
			else {
				rightPlayerBettingMoney = player[PlayerPosition::RIGHTPLAYER]->giveBettingMoneyToDealer();
				if (leftPlayerBettingMoney == 0) {
					giveUp = true;
					checkWinner(giveUp);
				}
				else {

				}
			}

		}
		void checkWinner(bool giveUp) {

		}
};
class Player
{
	private:
		string playerName;
		int playerMoney;
		int playerCardNumber;

	public:
		
		Player(string playerName) : playerName(playerName) {
			playerMoney = 5000000;
		}
		string getPlayerName() {
			return playerName;
		}
		void setPlayerCardNumber(int cardNumber) {
			this->playerCardNumber = cardNumber;
		}
		int getPlayerCardNumber() {
			return playerCardNumber;
		}
		int giveBasicBettingMoneyToDealer() {
			playerMoney -= BASIC_BET;
			return BASIC_BET;
		}
		
		int giveBettingMoneyToDealer() {
			int bettingMoney = 0;
			cout << "배팅할 금액을 입력하시오: ";
			//try catch 입력에 대하여
			cin >> bettingMoney;
			//if else
		}

};

class Board {
	private:
		int pageNumber;
		Dealer dealer;
	public:
		void startGame() {
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
		void openMenuPage() {
			indianPokerLogo();
			menuPageUI();

			Pointer nowPointer = { 32,16 };
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
					pageNumber = Page::WRITE_NAME;
					system("cls");
					this->startGame();
					return;
				}
			}
			return;
		}
		void openWriteNamePage() {
			indianPokerLogo();
			namePageUI();

			Pointer nowPointer = { 40,16 };
			string playerName;

			gotoxy(nowPointer);
			cin >> playerName;
			dealer.setPlayer(playerName, PlayerPosition::LEFTPLAYER);
			
			nowPointer.y += 2;
			gotoxy(nowPointer);
			cin >> playerName;
			dealer.setPlayer(playerName, PlayerPosition::RIGHTPLAYER);

			return;
		}
		void openStartGamePage() {
			return;
		}
		void openEndGamePage() {
			return;
		}
		Board() {
			pageNumber = Page::MENU;
		}
};

int main()
{
	consoleSize();
	consoleName();
	Board board;
	board.startGame();
	return 0;
}