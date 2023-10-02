#pragma once

#include "character.h"

class NPC : public Character
{
private:
	std::vector<Card> player_cards;
public:
	NPC();

	void print();

	void move(Card& cOT);

	Card select(Card& cOT);

	void draw();

	void pass();

	bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected);

	~NPC();
};