#include "Pile.h"


Pile::Pile()
{
}


Pile::~Pile()
{
}

int Pile::getNumOfCards() {
	return numOfCards;
}
void Pile::addCard(Card c) {
	cards[numOfCards] = c;
	numOfCards++;
}
int Pile::getTotal() {
	sum = 0;
	for (int i = 0; i < this->getNumOfCards(); i++) {
		sum += cards[i].getValue();
	}
	return sum;
}
bool Pile::isPrime() {
	if (numOfCards > 0) {
		int s = this->getTotal();
		if (s != 1) {
			for (int i = 2; i < s - 1; i++) {
				if (s%i == 0) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Pile::displayPile() {
	cout << "Pile: ";
	for (int i = 0; i < numOfCards; i++) {
		cards[i].displayCard();
		cout << ", ";
	}
	if (sum > 1) {
		cout << "Prime: " << sum << endl;
	}
	else {

	}
}

void Pile::displayLastPile() {
	cout << "Final Pile: ";
	for (int i = 0; i < numOfCards; i++) {
		cards[i].displayCard();
		cout << ", ";
	}
	cout << "Total: " << sum;
	if (isPrime()) {
		cout << " YOU WIN!" << endl;
	}
	else {
		cout << " You Lost..." << endl;
	}
}