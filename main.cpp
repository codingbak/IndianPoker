#include "board.h"
#define PAGE_COUNT 4

using namespace std;

int main()
{
	consoleSize();
	consoleName();
	Board board;
	board.startGame();
	return 0;
}