#include "card.h"



Card::Card(CardColor color) {
	
	cardColor = color;
	
	for (int i = 0; i < 10; i++) {
		cardNumber[i] = i;
	}
}


void Card::shuffleCard() {

	Sleep(950);
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < 10; i++) {
		int randomNumber = rand();
		std::swap(cardNumber[i], cardNumber[(int)randomNumber % 10]);
	}
}


int Card::getCard(int turn) {
	
	return cardNumber[turn];
}
