#include "game_manager.h"

//TODO add logic of making pase(hod)
//TODO rules of 101

int main()
{
	Character::getInstance<Deck>()->shuffling();

	bool isGame = false;
	bool wasDrawn = false;

	Character::getInstance<Player>();
	Character::getInstance<NPC>();

	Card cardOnTable = Character::getInstance<Deck>()->deck.back();
	std::vector<Card> usedCards;
	usedCards.push_back(cardOnTable);
	Character::getInstance<Deck>()->deck.pop_back();

	//DEMO lab3 with cards

	/*Card tmp;
	std::cin >> tmp;
	std::cout << tmp;

	Card copy(tmp);
	std::cout << copy;

	Card assigned = copy;
	std::cout << assigned;

	Card ace(1, 14);
	std::cout << ace;

	int comparison = assigned == ace;

	std::cout << comparison << std::endl;

	std::cin.get();*/

	std::cout << "Press any key to start the game." << std::endl;

	if (std::cin.get()) {
		isGame = true;
		do{
			refreshScreen(cardOnTable, usedCards, wasDrawn);
			if (Character::getInstance<Player>()->player_cards.empty() ||
				Character::getInstance<NPC>()->player_cards.empty()) {
				isGame = false;

				std::cout << Character::getInstance<Player>()->countScore<Player>() << std::endl;

				std::cout << Character::getInstance<NPC>()->countScore<NPC>() << std::endl;
			}
		} while (isGame);
	}
	return 0;
}