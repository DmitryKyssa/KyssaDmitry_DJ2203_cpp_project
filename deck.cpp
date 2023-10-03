#include "deck.h"
#include <algorithm>
#include <ctime>

Deck::Deck()
{
	for (auto& it_suits : suits) {
		for (auto& it_ranks : ranks) {
			Card tmp(it_suits.first, it_ranks.first);
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