#include "player.h"
#include<vector>
#include "game_basic_structs.h"
#include "operations_with_deck.h"

Player::Player(Deck _deck)
{
	int k = 1;
	//for (int i = 0; i < INITIAL_NUM_PLAYER_CARDS; i++) {
	for (int i = _deck.getDeck().size(); i != _deck.getDeck().size() - 4; i--) {
		player_cards.push_back(_deck.getDeck().back());
		_deck.getDeck().resize(_deck.getDeck().size()-1);
		k++;
	}
}

void Player::print()
{
	for (Card& it : player_cards) {
		std::cout << it;
	}
}

Player::~Player()
{
}
