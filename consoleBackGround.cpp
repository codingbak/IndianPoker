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
	
	int cardPointX = 0;

	if (cardColor == RED) {
		textColor(RED, WHITE);
		cardPointX = 10;
	}
	else {
		textColor(BLACK, WHITE);
		cardPointX = 100;
	}

	switch (cardNumber)
	{
	case 0 : 
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■■■    " << endl;
		gotoxy(cardPointX, 10);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 11);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 12);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 13);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 14);
		cout << "    ■■■■■" << endl;
		break;
	case 1:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "          ■  " << endl;
		gotoxy(cardPointX, 11);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 12);
		cout << "      ■      " << endl;
		gotoxy(cardPointX, 13);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 14);
		cout << "    ■■■■■" << endl;
		break;
	case 2:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 11);
		cout << "        ■■  " << endl;
		gotoxy(cardPointX, 12);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 14);
		cout << "      ■■■  " << endl;
		break;
	case 3:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 10);
		cout << "    ■  ■    " << endl;
		gotoxy(cardPointX, 11);
		cout << "    ■  ■    " << endl;
		gotoxy(cardPointX, 12);
		cout << "    ■■■■■" << endl;
		gotoxy(cardPointX, 13);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 14);
		cout << "        ■    " << endl;
		break;
	case 4:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "    ■■■■■" << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 10);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 11);
		cout << "    ■■■■  " << endl;
		gotoxy(cardPointX, 12);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 14);
		cout << "    ■■■■  " << endl;
		break;
	case 5:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "    ■        " << endl;
		gotoxy(cardPointX, 11);
		cout << "    ■■■■  " << endl;
		gotoxy(cardPointX, 12);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 14);
		cout << "      ■■■  " << endl;
		break;
	case 6:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "    ■■■■■" << endl;
		gotoxy(cardPointX, 9);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "          ■  " << endl;
		gotoxy(cardPointX, 11);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 12);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 13);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 14);
		cout << "        ■    " << endl;
		break;
	case 7:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 11);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 12);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 14);
		cout << "      ■■■  " << endl;
		break;
	case 8:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "              " << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "      ■■■  " << endl;
		gotoxy(cardPointX, 9);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 10);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 11);
		cout << "      ■■■■" << endl;
		gotoxy(cardPointX, 12);
		cout << "            ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 14);
		cout << "      ■■■  " << endl;
		break;
	case 9:
		gotoxy(cardPointX, 5);
		cout << "              " << endl;
		gotoxy(cardPointX, 6);
		cout << "    ■■■■■" << endl;
		gotoxy(cardPointX, 7);
		cout << "              " << endl;
		gotoxy(cardPointX, 8);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 9);
		cout << "      ■  ■  " << endl;
		gotoxy(cardPointX, 10);
		cout << "        ■    " << endl;
		gotoxy(cardPointX, 11);
		cout << "      ■  ■  " << endl;
		gotoxy(cardPointX, 12);
		cout << "    ■      ■" << endl;
		gotoxy(cardPointX, 13);
		cout << "              " << endl;
		gotoxy(cardPointX, 14);
		cout << "    ■■■■■" << endl;
		break;
	}

	textColor(WHITE, BLACK);
}

void gamePageBettingUI() {
	gotoxy(58, 7);
	cout << "베팅 금액";
	gotoxy(58, 11);
	cout << "CALL 금액";
}
void gamePagePlayerUI(std::string namePlayerA, std::string namePlayerB) {
	gotoxy(10,17);
	cout << namePlayerA<< " Player";
	gotoxy(10, 21);
	cout << "현재 자본";
	gotoxy(25, 9);
	cout << "현재 게임 베팅";
	gotoxy(10, 24);
	cout << "베팅금을 입력하시오";
	gotoxy(100, 17);
	cout << namePlayerB <<" Player";
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

void gamePageGameTipUI() {
	gotoxy(58, 30);
	cout << "★게임 꿀팁★";
	gotoxy(38, 31);
	cout << "※ 다이를 외치는 방법은 베팅 금액을 0을 입력하면 됩니다.";
	gotoxy(38, 32);
	cout << "※ 10을 들고 다이를 외치면 패널티 1000000을 잃게 됩니다.";

}

void endPageWinnerUI(std::string winnerPlayer)
{
	for(int i=0; i<100; i++){
	gotoxy(45, 30);
	cout << "★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆";
	gotoxy(53, 31);
	cout << winnerPlayer << "플레이어님 축하드립니다 :)";
	gotoxy(45, 32);
	cout << "★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆";
	Sleep(50);
	gotoxy(45, 30);
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★";
	gotoxy(45, 32);
	cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★";
	Sleep(50);
	}
}