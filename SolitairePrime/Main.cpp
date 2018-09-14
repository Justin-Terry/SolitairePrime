#include <iostream>
#include "card.h"
#include "deck.h"
#include "Pile.h"

using namespace std;


int main() {
	Deck theDeck;
	int selection;
	int nextPile;
	int lastTotal;
	bool playing = true;

	while (playing) {
		cout << "===========================" << endl;
		cout << "Welcome to Solitaire Prime!" << endl;
		cout << "1.) New Deck\n2.) Display Deck\n3.) Shuffle Deck\n4.) Play Solitaire Prime\n5.) Exit\n";
		cout << "===========================" << endl;
		Pile piles[50];
		while (true) {
			try {
				cin >> selection;
				if ((selection > 0) && (selection < 6)) {
					break;
				}
				else {
					cout << "Invalid selection try again" << endl;
				}
			}
			catch (exception) {
				cout << "Invalid selection try again" << endl;
			}

		}

		switch (selection) {
		case 1:
			theDeck = Deck();
			break;
		case 2:
			theDeck.display();
			break;
		case 3:
			theDeck.shuffle();
			theDeck.display();
			break;
		case 4:
			cout << "PLAYING SOLITAIRE PRIME!!!" << endl;
			lastTotal = 0;
			nextPile = 0;
			while (!theDeck.isEmpty()) {
				while (!piles[nextPile].isPrime() && !theDeck.isEmpty()) {
					if (!theDeck.isEmpty()) {
						piles[nextPile].addCard(theDeck.deal());
					}
				}
				if (!theDeck.isEmpty()) {
					piles[nextPile].displayPile();
					cout << endl;
					nextPile++;
				}
			

			}
			piles[nextPile].displayLastPile();
			cout << "Number of Piles: " << (nextPile+1) << endl;

			break;
		case 5:
			return 0;
		}
	}

	cin.get();
	return(0);
}

