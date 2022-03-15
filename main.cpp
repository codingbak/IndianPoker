#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include "board.h"

#define PAGE_COUNT 4

using namespace std;

// 리팩토링 시작
int main() {
	consoleSize();
	consoleName();
	
	Board board;
	board.startGame();
	
	return 0;
}