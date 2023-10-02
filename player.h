#pragma once

#include "character.h"

class Player : public Character
{
public:
	
	static Player* Instance;

	Player();

	std::vector<Card> player_cards;

	bool canMove;

	void move(Card& cOT, int counter);

	Card select(Card& cOT);

	void draw();

	void pass();

	bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected);

	~Player();
};