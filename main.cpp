#include "board.h"

#define PAGE_COUNT 4

using namespace std;

// �����丵 ����
int main() {
	consoleSize();
	consoleName();
	
	Board board;
	board.startGame();
	
	return 0;
}