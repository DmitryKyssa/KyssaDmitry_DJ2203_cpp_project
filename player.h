#pragma once

#include <vector>
#include "game_basic_structs.h"

const int INITIAL_NUM_PLAYER_CARDS = 4;

class Player
{
	private:
		std::vector<Card> player_cards;
	public:
	Player();

	void print();

	Card select();

	~Player();
};