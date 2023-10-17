#pragma once

#include "character.h"

class NPC : public Character
{
public:
	static NPC* Instance;

	NPC();

	std::vector<Card> player_cards;

	int score = 0;

	bool canMove;

	void move(Card& cOT, int counter);

	Card select(Card& cOT);

	void draw();

	void pass();

	bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected);

	int countScore();

	~NPC();
};