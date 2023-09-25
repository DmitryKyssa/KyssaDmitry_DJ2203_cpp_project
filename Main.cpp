// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "player.h"
#include <algorithm>
#include <iterator>

int main()
{
	//Creating deck of cards

	Deck::getInstance()->shuffling();

	//Print all cards name
	/*for (Card &it: deck) {
		std::cout << it;
	}*/

	Player* player = new Player();
	player->print();

	std::cout << std::endl;

	Player* npc = new Player();
	npc->print();

	return 0;
}
