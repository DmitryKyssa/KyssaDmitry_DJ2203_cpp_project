#pragma once

#include <vector>
#include "card.h"

class Deck
{
private:

public:
	static Deck* Instance;

	Deck();

	std::vector<Card> deck;

	void shuffling();

	~Deck();
};