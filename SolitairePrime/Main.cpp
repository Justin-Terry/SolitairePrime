//Justin Terry
// Class (CECS 275-05)
// Project Name (Prog 1 - Solitaire Prime)
// Due Date (Sep 20, 2018)

#include <iostream>
#include "card.h"
#include "deck.h"
#include "Pile.h"

using namespace std;


int main() {
	// Create a deck
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

		// Create a bunch of piles (50 is more than enough for one deck of cards)
		Pile piles[50];
		while (true) {
			cout << "What is your selection?: ";
			cin >> selection;
				
				// Check for valid input
				if ((selection > 0) && (selection < 6) && cin.good()) {
					break;
				}
				// Clear cin and display message if invalid input
				else {
					cin.clear();
					cin.ignore();
					cout << "Invalid Selection, try again." << endl;
				}

		}
		// Process selection
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
			// if the deck is not empty and the pile is not prime
			while (!theDeck.isEmpty()) {
				while (!piles[nextPile].isPrime() && !theDeck.isEmpty()) {
					// Deal the next card into the pile
						piles[nextPile].addCard(theDeck.deal());					
				}
				// if the deck is empty display the pile and move on
				if (!theDeck.isEmpty()) {
					piles[nextPile].displayPile();
					cout << endl;
					nextPile++;
				}
			

			}
			// Display the last pile and check it for win/loss
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

