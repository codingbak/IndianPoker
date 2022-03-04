#include "consoleBackGround.h"


#define BLACK 0
#define RED 4
#define WHITE 15

using namespace std;

void menuPageUI() {
	gotoxy(50, 22);
	cout << "Game Start";
	gotoxy(50, 23);
	cout << "Game End";
}
void namePageUI() {
	gotoxy(40, 22);
	cout << "Player 1 이름을 입력하시오 : ";
	gotoxy(40, 24);
	cout << "Player 2 이름을 입력하시오 : ";
}


void indianPokerLogo() {
	textColor(RED, WHITE);
	gotoxy(15, 13);
	cout << "■■■■■" << endl;
	gotoxy(15, 14);
	cout << "    ■    " << endl;
	gotoxy(15, 15);
	cout << "    ■    " << endl;
	gotoxy(15, 16);
	cout << "    ■    " << endl;
	gotoxy(15, 17);
	cout << "    ■    " << endl;
	gotoxy(15, 18);
	cout << "    ■    " << endl;
	gotoxy(15, 19);
	cout << "■■■■■" << endl;

	textColor(BLACK, WHITE);
	gotoxy(30, 13);
	cout << "■■    ■" << endl;
	gotoxy(30, 14);
	cout << "■ ■   ■" << endl;
	gotoxy(30, 15);
	cout << "■  ■  ■" << endl;
	gotoxy(30, 16);
	cout << "■   ■ ■" << endl;
	gotoxy(30, 17);
	cout << "■    ■■" << endl;
	gotoxy(30, 18);
	cout << "■      ■" << endl;
	gotoxy(30, 19);
	cout << "■      ■" << endl;

	textColor(RED, WHITE);
	gotoxy(45, 13);
	cout << "■■      " << endl;
	gotoxy(45, 14);
	cout << "■  ■    " << endl;
	gotoxy(45, 15);
	cout << "■    ■  " << endl;
	gotoxy(45, 16);
	cout << "■      ■" << endl;
	gotoxy(45, 17);
	cout << "■    ■  " << endl;
	gotoxy(45, 18);
	cout << "■  ■    " << endl;
	gotoxy(45, 19);
	cout << "■■      " << endl;

	textColor(BLACK, WHITE);
	gotoxy(60, 13);
	cout << "■■■■■" << endl;
	gotoxy(60, 14);
	cout << "    ■    " << endl;
	gotoxy(60, 15);
	cout << "    ■    " << endl;
	gotoxy(60, 16);
	cout << "    ■    " << endl;
	gotoxy(60, 17);
	cout << "    ■    " << endl;
	gotoxy(60, 18);
	cout << "    ■    " << endl;
	gotoxy(60, 19);
	cout << "■■■■■" << endl;

	textColor(RED, WHITE);
	gotoxy(75, 13);
	cout << "■■■■■" << endl;
	gotoxy(75, 14);
	cout << "■      ■" << endl;
	gotoxy(75, 15);
	cout << "■      ■" << endl;
	gotoxy(75, 16);
	cout << "■■■■■" << endl;
	gotoxy(75, 17);
	cout << "■      ■" << endl;
	gotoxy(75, 18);
	cout << "■      ■" << endl;
	gotoxy(75, 19);
	cout << "■      ■" << endl;

	textColor(BLACK, WHITE);
	gotoxy(90, 13);
	cout << "■■    ■" << endl;
	gotoxy(90, 14);
	cout << "■ ■   ■" << endl;
	gotoxy(90, 15);
	cout << "■  ■  ■" << endl;
	gotoxy(90, 16);
	cout << "■   ■ ■" << endl;
	gotoxy(90, 17);
	cout << "■    ■■" << endl;
	gotoxy(90, 18);
	cout << "■      ■" << endl;
	gotoxy(90, 19);
	cout << "■      ■" << endl;
	
	textColor(WHITE, BLACK);
}
void gamePageCardUI(int cardNumber, int cardColor) {

	textColor(RED, WHITE);
	gotoxy(10, 5);
	cout << "              " << endl;
	gotoxy(10, 6);
	cout << "              " << endl;
	gotoxy(10, 7);
	cout << "              " << endl;
	gotoxy(10, 8);
	cout << "        ■    " << endl;
	gotoxy(10, 9);
	cout << "    ■■■    " << endl;
	gotoxy(10, 10);
	cout << "        ■    " << endl;
	gotoxy(10, 11);
	cout << "        ■    " << endl;
	gotoxy(10, 12);
	cout << "        ■    " << endl;
	gotoxy(10, 13);
	cout << "        ■    " << endl;
	gotoxy(10, 14);
	cout << "    ■■■■■" << endl;


	textColor(BLACK, WHITE);
	gotoxy(100, 5);
	cout << "              " << endl;
	gotoxy(100, 6);
	cout << "              " << endl;
	gotoxy(100, 7);
	cout << "              " << endl;
	gotoxy(100, 8);
	cout << "      ■■■  " << endl;
	gotoxy(100, 9);
	cout << "    ■      ■" << endl;
	gotoxy(100, 10);
	cout << "          ■  " << endl;
	gotoxy(100, 11);
	cout << "        ■    " << endl;
	gotoxy(100, 12);
	cout << "      ■      " << endl;
	gotoxy(100, 13);
	cout << "    ■        " << endl;
	gotoxy(100, 14);
	cout << "    ■■■■■" << endl;
	/*
	gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "      ■■■  " << endl;
	gotoxy(asdf, 9);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 10);
	cout << "            ■" << endl;
	gotoxy(asdf, 11);
	cout << "        ■■  " << endl;
	gotoxy(asdf, 12);
	cout << "            ■" << endl;
	gotoxy(asdf, 13);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 14);
	cout << "      ■■■  " << endl;

	gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "    ■        " << endl;
	gotoxy(asdf, 9);
	cout << "    ■        " << endl;
	gotoxy(asdf, 10);
	cout << "    ■  ■    " << endl;
	gotoxy(asdf, 11);
	cout << "    ■  ■    " << endl;
	gotoxy(asdf, 12);
	cout << "    ■■■■■" << endl;
	gotoxy(asdf, 13);
	cout << "        ■    " << endl;
	gotoxy(asdf, 14);
	cout << "        ■    " << endl;

	gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "    ■■■■■" << endl;
	gotoxy(asdf, 9);
	cout << "    ■        " << endl;
	gotoxy(asdf, 10);
	cout << "    ■        " << endl;
	gotoxy(asdf, 11);
	cout << "    ■■■■  " << endl;
	gotoxy(asdf, 12);
	cout << "            ■" << endl;
	gotoxy(asdf, 13);
	cout << "            ■" << endl;
	gotoxy(asdf, 14);
	cout << "    ■■■■  " << endl;

	gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "      ■■■  " << endl;
	gotoxy(asdf, 9);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 10);
	cout << "    ■        " << endl;
	gotoxy(asdf, 11);
	cout << "    ■■■■  " << endl;
	gotoxy(asdf, 12);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 13);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 14);
	cout << "      ■■■  " << endl;

		gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "    ■■■■■" << endl;
	gotoxy(asdf, 9);
	cout << "            ■" << endl;
	gotoxy(asdf, 10);
	cout << "          ■  " << endl;
	gotoxy(asdf, 11);
	cout << "        ■    " << endl;
	gotoxy(asdf, 12);
	cout << "        ■    " << endl;
	gotoxy(asdf, 13);
	cout << "        ■    " << endl;
	gotoxy(asdf, 14);
	cout << "        ■    " << endl;

	gotoxy(asdf, 5);
	cout << "              " << endl;
	gotoxy(asdf, 6);
	cout << "              " << endl;
	gotoxy(asdf, 7);
	cout << "              " << endl;
	gotoxy(asdf, 8);
	cout << "      ■■■  " << endl;
	gotoxy(asdf, 9);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 10);
	cout << "    ■        " << endl;
	gotoxy(asdf, 11);
	cout << "    ■■■■  " << endl;
	gotoxy(asdf, 12);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 13);
	cout << "    ■      ■" << endl;
	gotoxy(asdf, 14);
	cout << "      ■■■  " << endl;
	*/
	if (cardColor == RED) {
		textColor(BLACK, RED);
		gotoxy(10, 16);
		cout << cardNumber<<endl;
	}
	else {
		textColor(BLACK, WHITE);
		gotoxy(100, 16);
		cout << cardNumber<<endl;
	}
	textColor(WHITE, BLACK);
}

void gamePageBettingUI() {
	gotoxy(58, 7);
	cout << "베팅 금액";
	gotoxy(58, 11);
	cout << "CALL 금액";
}
void gamePagePlayerUI() {
	gotoxy(10,17);
	cout << "Player A";
	gotoxy(10, 21);
	cout << "현재 자본";
	gotoxy(25, 9);
	cout << "현재 게임 베팅";
	gotoxy(10, 24);
	cout << "베팅금을 입력하시오";
	gotoxy(100, 17);
	cout << "Player B";
	gotoxy(100, 21);
	cout << "현재 자본";
	gotoxy(85, 9);
	cout << "현재 게임 베팅";
	gotoxy(100, 24);
	cout << "베팅금을 입력하시오";
}
void gamePagePlayerInfoInsertUI(GamePageInfo gamePageInfo) {
	gotoxy(59, 8);
	cout << gamePageInfo.currentAllBettingMoney;
	gotoxy(59, 12);
	cout << gamePageInfo.currentCallBettingMoney;
	gotoxy(11, 22);
	cout << gamePageInfo.leftPlayerMoney;
	gotoxy(26, 10);
	cout << gamePageInfo.leftPlayerBettingMoney;
	gotoxy(101, 22);
	cout << gamePageInfo.rightPlayerMoney;
	gotoxy(86, 10);
	cout << gamePageInfo.rightPlayerBettingMoney;
}