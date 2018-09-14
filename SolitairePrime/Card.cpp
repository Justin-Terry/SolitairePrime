#include "Card.h"



Card::Card(char r, char s)
{
	rank = r;
	suit = s;
	faceUp = false;
}
Card::Card() {};
char Card::getRank() {
	return rank;
}


char Card::getSuit() {
	return suit;
}

bool Card::isFaceUp() {
	return faceUp;
}

void Card::setValue(int n) {
	value = n;
}
int Card::getValue() {
	return value;
}

void Card::displayCard() {
	if (getRank() == 'T') {
		cout << "10";
	}
	else {
		cout << getRank();
	}
	cout << getSuit();
}

