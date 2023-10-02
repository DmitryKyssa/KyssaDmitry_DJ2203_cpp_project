#pragma once

#include <vector>
#include "game_basic_structs.h"

const int INITIAL_NUM_PLAYER_CARDS = 4;

class Character {
public:
	virtual void print() = 0;

	virtual void move(Card& cOT) = 0;

	virtual Card select(Card& cOT) = 0;

	virtual void draw() = 0;

	virtual void pass() = 0;

	virtual bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected) = 0;
};