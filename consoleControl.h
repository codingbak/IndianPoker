#include <windows.h>

struct Pointer
{
	int x;
	int y;
};
void gotoxy(Pointer point);
void gotoxy(int x, int y);
