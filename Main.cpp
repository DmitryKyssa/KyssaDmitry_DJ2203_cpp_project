// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "player.h"
#include "windows.h"

int main()
{
	Deck::getInstance()->shuffling();

	//Print all cards name
	/*for (Card &it: deck) {
		std::cout << it;
	}*/
	bool isGame = false;

	Player* player = new Player();
	Player* npc = new Player();
	Card cardOnTable = Deck::getInstance()->deck.back();

	std::cout << "Enter key 'p' to start the game." << std::endl;

	if (std::cin.get()) {
		isGame = true;
		while (isGame) {
			system("cls");

			player->print();

			std::cout << std::endl;

			std::cout << cardOnTable << std::endl;

			std::cout << std::endl;

			npc->print();

			cardOnTable = player->select();

			Sleep(3000);
		}
	}
	return 0;
}
