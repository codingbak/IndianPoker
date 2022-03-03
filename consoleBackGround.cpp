#include "consoleBackGround.h"
#include <iostream>

#define BLACK 0
#define RED 4
#define WHITE 15

using namespace std;

void menuPageUI() {
	gotoxy(34, 16);
	cout << "Game Start";
	gotoxy(34, 17);
	cout << "Game End";
}
void namePageUI() {
	gotoxy(10, 16);
	cout << "Player 1 이름을 입력하시오 : ";
	gotoxy(10, 18);
	cout << "Player 2 이름을 입력하시오 : ";
}


void indianPokerLogo() {
	textColor(RED, WHITE);
	gotoxy(5, 5);
	cout << "■■■■■" << endl;
	gotoxy(5, 6);
	cout << "    ■    " << endl;
	gotoxy(5, 7);
	cout << "    ■    " << endl;
	gotoxy(5, 8);
	cout << "    ■    " << endl;
	gotoxy(5, 9);
	cout << "    ■    " << endl;
	gotoxy(5, 10);
	cout << "    ■    " << endl;
	gotoxy(5, 11);
	cout << "■■■■■" << endl;

	textColor(BLACK, WHITE);
	gotoxy(17, 5);
	cout << "■■    ■" << endl;
	gotoxy(17, 6);
	cout << "■ ■   ■" << endl;
	gotoxy(17, 7);
	cout << "■  ■  ■" << endl;
	gotoxy(17, 8);
	cout << "■   ■ ■" << endl;
	gotoxy(17, 9);
	cout << "■    ■■" << endl;
	gotoxy(17, 10);
	cout << "■      ■" << endl;
	gotoxy(17, 11);
	cout << "■      ■" << endl;

	textColor(RED, WHITE);
	gotoxy(29, 5);
	cout << "■■      " << endl;
	gotoxy(29, 6);
	cout << "■  ■    " << endl;
	gotoxy(29, 7);
	cout << "■    ■  " << endl;
	gotoxy(29, 8);
	cout << "■      ■" << endl;
	gotoxy(29, 9);
	cout << "■    ■  " << endl;
	gotoxy(29, 10);
	cout << "■  ■    " << endl;
	gotoxy(29, 11);
	cout << "■■      " << endl;

	textColor(BLACK, WHITE);
	gotoxy(41, 5);
	cout << "■■■■■" << endl;
	gotoxy(41, 6);
	cout << "    ■    " << endl;
	gotoxy(41, 7);
	cout << "    ■    " << endl;
	gotoxy(41, 8);
	cout << "    ■    " << endl;
	gotoxy(41, 9);
	cout << "    ■    " << endl;
	gotoxy(41, 10);
	cout << "    ■    " << endl;
	gotoxy(41, 11);
	cout << "■■■■■" << endl;

	textColor(RED, WHITE);
	gotoxy(53, 5);
	cout << "■■■■■" << endl;
	gotoxy(53, 6);
	cout << "■      ■" << endl;
	gotoxy(53, 7);
	cout << "■      ■" << endl;
	gotoxy(53, 8);
	cout << "■■■■■" << endl;
	gotoxy(53, 9);
	cout << "■      ■" << endl;
	gotoxy(53, 10);
	cout << "■      ■" << endl;
	gotoxy(53, 11);
	cout << "■      ■" << endl;

	textColor(BLACK, WHITE);
	gotoxy(65, 5);
	cout << "■■    ■" << endl;
	gotoxy(65, 6);
	cout << "■ ■   ■" << endl;
	gotoxy(65, 7);
	cout << "■  ■  ■" << endl;
	gotoxy(65, 8);
	cout << "■   ■ ■" << endl;
	gotoxy(65, 9);
	cout << "■    ■■" << endl;
	gotoxy(65, 10);
	cout << "■      ■" << endl;
	gotoxy(65, 11);
	cout << "■      ■" << endl;
	
	textColor(WHITE, BLACK);
}

