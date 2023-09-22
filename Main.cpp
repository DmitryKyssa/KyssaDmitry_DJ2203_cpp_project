// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "operations_with_deck.h"
#include "player.h"

int main()
{
	//Creating deck of cards
	Deck* deck = new Deck();

	deck->shuffling();

	//Print all cards name
	/*for (Card &it: deck) {
		std::cout << it;
	}*/

	/*int i = 1;
	for (Card& it : deck) {
		std::cout << i << " " << it ;
		i++;
	}*/

	Player* player = new Player(*deck);
	player->print();

	return 0;
}
