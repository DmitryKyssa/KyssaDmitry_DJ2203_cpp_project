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
	int input = 1;
	std::cin >> input;
	return player_cards.at(input-1);
}

Player::~Player()
{
}
