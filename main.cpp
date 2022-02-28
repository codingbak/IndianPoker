#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <conio.h>
#include "consoleControl.h"



#define UP 72
#define DOWN 80
#define BASIC_BET 100000
#define PAGE_COUNT 4
using namespace std;

enum class Color {
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
		Color cardColor;

	public:
		Card(Color color)
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
		
		int giveBasicBettingMoneyToDealer() {
			playerMoney -= BASIC_BET;
			return BASIC_BET;
		}
		
		int giveFirstBettingMoneyToDealer() {
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
		Pointer nowPointer = {18,6};
	public:
		void OpenMenuPage() {
			gotoxy(nowPointer);
			cout << "▶";
			gotoxy(20,6);
			cout << "Game Start";
			gotoxy(20, 7);
			cout << "Game End";
			if (_kbhit()) {
				int pressedKey = _getch();
				switch (pressedKey) {
					case UP:
						nowPointer.y -= 1;
						system("cls");
						OpenMenuPage();
						break;
					case DOWN:
						nowPointer.y += 1;
						system("cls");
						OpenMenuPage();
						break;
				}
			}
			return;
		}
		void OpenWriteNamePage() {
			return;
		}
		void OpenStartGamePage() {
			return;
		}
		void OpenEndGamePage() {
			return;
		}
		Board() {
			pageNumber = Page::MENU;
			switch (pageNumber)
			{
				case Page::MENU:
					OpenMenuPage();
					break;
				case Page::WRITE_NAME:
					OpenWriteNamePage();
					break;
				case Page::START_GAME:
					OpenStartGamePage();
					break;
				case Page::END_GAME:
					OpenEndGamePage();
					break;
			}
		}
};

int main()
{
	Board board;
	return 0;
}