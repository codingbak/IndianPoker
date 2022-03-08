#pragma once
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>


enum CardColor {
	RED = 4,
	BLACK = 0
};



class Card {

private:
	int cardNumber[10];
	CardColor cardColor;


public:
	Card(CardColor color);
	void shuffleCard();
	int getCard(int turn);
};

