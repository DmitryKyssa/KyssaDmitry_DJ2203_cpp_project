#include "deck.h"
#include <algorithm>
#include <ctime>

Deck::Deck()
{
	for (int i = 0; i < sizeof(allSuits) / sizeof(allSuits[0]); i++) {
		for (int j = 0; j < sizeof(allRanks) / sizeof(allRanks[0]); j++) {
			Card tmp(i, j);
			deck.push_back(tmp);
		}
	}
}

void Deck::shuffling() {
	srand((unsigned int)time(NULL));
	std::vector<Card> tmp(this->deck.begin(), this->deck.end());
	std::random_shuffle(tmp.begin(), tmp.end());
	std::copy(tmp.begin(), tmp.end(), this->deck.begin());
}

Deck* Deck::Instance = nullptr;

Deck::~Deck() {}