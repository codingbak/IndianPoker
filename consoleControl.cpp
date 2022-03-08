#include "consoleControl.h"



void gotoxy(int x, int y) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


void gotoxy(Pointer point) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = point.x;
	pos.Y = point.y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


void textColor(int foreground, int background) {

	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void consoleSize() {

	system("mode con cols=130 lines=40");
}


void consoleName() {

	SetConsoleTitle("Indian Poker");
}



CursorControl::CursorControl(Pointer nowPointer) : pointer(nowPointer) {
}



Pointer CursorControl::cursorMove() {

	if (_kbhit()) {
		int pressedKey = _getch();
		switch (pressedKey) {
		case UP:
			pointer.y -= 1;
			system("cls");
			break;
		case DOWN:
			pointer.y += 1;
			system("cls");
			break;
		}
	}

	return pointer;
}
bool CursorControl::cursorClick() {

	if (_kbhit()) {
		int pressedKey = _getch();
		if (pressedKey == ENTER) {
			return true;
		}
	}

	return false;
}

