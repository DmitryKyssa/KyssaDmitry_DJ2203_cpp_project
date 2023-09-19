// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"

int main()
{
	Card deck[36];

	//Creating deck of cards
	for (auto& it_suits : suits) {
		for (auto& it_ranks : ranks) {
			deck[(it_suits.first - 1) * ranks.size() + (it_ranks.first - 6)] = Card(it_suits.first, it_ranks.first);
		}
	}

	//Print all cards name
	for (Card it: deck) {
		it.print();
	}

	Card exemple{10, 10};
	exemple.print();

	return 0;
}
