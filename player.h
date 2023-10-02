#pragma once

#include "character.h"

class Player : public Character
{
private:
	std::vector<Card> player_cards;
public:
	Player();

	void print();

	void move(Card& cOT);

	Card select(Card& cOT);

	void draw();

	void pass();

	bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected);

	~Player();
};