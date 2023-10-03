#include "card.h"
#include "deck.h"
#include "player.h"
#include "windows.h"
#include "npc.h"

//TODO add logic of making pase(hod)
//TODO rules of 101
//TODO add a score
//TODO clear screen after draw a card
//TODO overload operations with cards (>, <, == (maybe, spaceship))

int main()
{
	Character::getInstance<Deck>()->shuffling();

	bool isGame = false;

	Character::getInstance<Player>();
	Character::getInstance<NPC>();

	Card cardOnTable = Character::getInstance<Deck>()->deck.back();
	std::vector<Card> usedCards;
	usedCards.push_back(cardOnTable);
	Character::getInstance<Deck>()->deck.pop_back();

	std::cout << "Press any key to start the game." << std::endl;

	if (std::cin.get()) {
		isGame = true;
		while (isGame) {
			system("cls");

			std::cout << "Player's cards:" << std::endl;
			Character::getInstance<Player>()->print <Player>();

			std::cout << std::endl;

			std::cout << "Card on table: ";
			std::cout << cardOnTable << "Number of cards in deck: " << Character::getInstance<Deck>()->deck.size() << std::endl;

			std::cout << std::endl;

			std::cout << "NPC's cards:" << std::endl;
			Character::getInstance<NPC>()->print <NPC>();

			std::cout << std::endl;

			std::cout << "Cards in deck:" << std::endl;
			for (Card& it : Character::getInstance<Deck>()->deck) {
				std::cout << it;
			}

			std::cout << std::endl;

			std::cout << "Used cards:" << std::endl;
			for (Card& it : usedCards) {
				std::cout << it;
			}

			std::cout << std::endl;

			int counter = 0;

			if (Character::getInstance<Player>()->canMove) {
				Character::getInstance<Player>()->move(cardOnTable, counter);
				Character::getInstance<NPC>()->canMove = true;
			}

			usedCards.push_back(cardOnTable);

			if (Character::getInstance<NPC>()->canMove) {
				Character::getInstance<NPC>()->move(cardOnTable, counter);
				Character::getInstance<Player>()->canMove = true;
			}

			usedCards.push_back(cardOnTable);

			Sleep(2000);
		}
	}
	return 0;
}