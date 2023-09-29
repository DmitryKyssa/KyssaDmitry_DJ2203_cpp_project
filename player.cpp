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

Card Player::select()
{
	std::cout << "Please, select a card" << std::endl;
	std::cout << "Enter a number (1 - first card...)" << std::endl;
	int input;
	do
	{
		std::cin >> input;
	} while (!checkIfMoveIsCorrect(input));

	Card tmp = player_cards.at(input - 1);
	player_cards.erase(player_cards.begin() + input - 1);
	return tmp;
}

bool Player::checkIfMoveIsCorrect(int _input)
{
	if (_input >= 1 && _input <= (int)player_cards.size()) {
		return true;
	}
	else {
		std::cout << "Incorrect input!" << std::endl;
		return false;
	}
}

Player::~Player()
{
}
