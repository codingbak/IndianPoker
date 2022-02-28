#include "consoleControl.h"
#include <windows.h>

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