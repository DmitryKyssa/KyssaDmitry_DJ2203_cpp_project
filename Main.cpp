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

			std::cout << "Player's cards:" << std::endl;
			player->print();

			std::cout << std::endl;

			std::cout << "Card on table: ";
			std::cout << cardOnTable << "Number of cards in deck: " << Deck::getInstance()->deck.size() << std::endl;

			std::cout << std::endl;

			std::cout << "NPC's cards:" << std::endl;
			npc->print();

			std::cout << std::endl;

			Deck::getInstance()->deck.push_back(cardOnTable);
			cardOnTable = player->select();

			Sleep(3000);
		}
	}
	return 0;
}
