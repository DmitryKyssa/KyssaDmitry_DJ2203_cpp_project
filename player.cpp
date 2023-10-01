#include "player.h"
#include <vector>
#include "game_basic_structs.h"

Player::Player()
{
	for (int i = 0; i < INITIAL_NUM_PLAYER_CARDS; i++) {
		player_cards.push_back(Deck::getInstance()->deck.back());
		Deck::getInstance()->deck.pop_back();
	}
}

void Player::print()
{
	for (Card& it : player_cards) {
		std::cout << it;
	}
}

Card Player::select(Card& cOT)
{
	std::cout << "Please, select a card" << std::endl;
	std::cout << "Enter a number (1 - first card...)" << std::endl;
	int input;
	Card tmp;
	do
	{
		std::cin >> input;
		tmp = player_cards.at(input - 1);
	} while (!checkIfRangeIsCorrect(input, cOT, tmp));

	player_cards.erase(player_cards.begin() + input - 1);
	return tmp;
}

bool Player::checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected)
{
	if (_input >= 1 && _input <= (int)player_cards.size()) {
		if (onTable.getRank() == selected.getRank()
			|| onTable.getSuit() == selected.getSuit()
			|| selected.getRank() == "Jack") {
			return true;
		}
		else {
			std::cout << "Card must be the suit " << onTable.getSuit() << " or rank"
				<< onTable.getRank() << " or a Jack!" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Incorrect input! Enter a number from 1 to " << player_cards.size() << std::endl;
		return false;
	}
}

Player::~Player()
{
}
