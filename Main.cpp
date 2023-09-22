// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "operations_with_deck.h"

int main()
{
	std::vector<Card> deck;

	//Creating deck of cards
	for (auto& it_suits : suits) {
		for (auto& it_ranks : ranks) {
			Card* tmp = new Card(it_suits.first, it_ranks.first);
			deck.push_back(*tmp);
			//deck[(it_suits.first - 1) * ranks.size() + (it_ranks.first - 6)] = Card(it_suits.first, it_ranks.first);
		}
	}

	//Print all cards name
	/*for (Card &it: deck) {
		std::cout << it;
	}*/

	deck = shuffling(deck);

	int i = 1;
	for (Card& it : deck) {
		std::cout << i << " " << it ;
		i++;
	}

	return 0;
}
