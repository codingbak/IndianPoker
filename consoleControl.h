#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#define UP 72
#define DOWN 80
#define ENTER 32
struct Pointer
{
	int x;
	int y;
};
class CursorControl {
private:
	Pointer pointer;
public:
	CursorControl(Pointer nowPointer);
	Pointer cursorMove();
	bool cursorClick();
};
void gotoxy(Pointer point);
void gotoxy(int x, int y);
void textColor(int foreground, int background);
void consoleSize();
void consoleName();