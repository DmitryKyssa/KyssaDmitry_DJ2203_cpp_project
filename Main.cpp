// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "operations_with_deck.h"

int main()
{
	std::list<Card> initialDeck;

	//Creating deck of cards
	for (auto& it_suits : suits) {
		for (auto& it_ranks : ranks) {
			Card* tmp = new Card(it_suits.first, it_ranks.first);
			initialDeck.push_back(*tmp);
			//deck[(it_suits.first - 1) * ranks.size() + (it_ranks.first - 6)] = Card(it_suits.first, it_ranks.first);
		}
	}

	//Print all cards name
	for (Card &it: initialDeck) {
		std::cout << it;
	}

	Card exemple{10, 20};
	std::cout << exemple;

	return 0;
}
