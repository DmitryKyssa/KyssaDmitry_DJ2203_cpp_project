// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"
#include "player.h"
#include "windows.h"

//TODO add logic of get a card from deck
//TODO add logic of making pase(hod)
//TODO rules of 101
//TODO add a score
//TODO divide player and npc by creating 2 different classes inherited from one abstract character

int main()
{
	Deck::getInstance()->shuffling();

	bool isGame = false;
	bool playerCanMove = true;

	Player* player = new Player();
	Player* npc = new Player();
	Card cardOnTable = Deck::getInstance()->deck.back();
	std::vector<Card> usedCards;
	usedCards.push_back(cardOnTable);
	Deck::getInstance()->deck.pop_back();

	std::cout << "Press any key to start the game." << std::endl;

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

			std::cout << "Cards in deck:" << std::endl;
			for (Card& it : Deck::getInstance()->deck) {
				std::cout << it;
			}

			std::cout << std::endl;

			std::cout << "Used cards:" << std::endl;
			for (Card& it : usedCards) {
				std::cout << it;
			}

			std::cout << std::endl;

			if (playerCanMove) {
				player->move(cardOnTable);
				!playerCanMove;
			}
			else {
				//npc move
			}

			usedCards.push_back(cardOnTable);

			Sleep(2000);
		}
	}
	return 0;
}