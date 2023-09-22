#include "game_basic_structs.h"
#include <algorithm>
#include <ctime>

//default constructor
Card::Card() {}

//constructor with parameters
Card::Card(int _suit, int _rank) {
	if (suits.find(_suit) != suits.end()) {
		this->suit = suits.at(_suit);
	}
	else {
		std::cout << "This suit doesn't exist!";
	}

	if (ranks.find(_rank) != ranks.end()) {
		this->rank = ranks.at(_rank);
	}
	else {
		std::cout << "This rank doesn't exist!";
	}
}

std::string Card::getSuit() { return this->suit; }

std::string Card::getRank() { return this->rank; }

std::ostream& operator<<(std::ostream& out, Card& card) {
	return out << card.getRank() << " " << card.getSuit() << std::endl;
}

Card::~Card() {}

Deck::Deck()
{
	for (auto& it_suits : suits) {
		for (auto& it_ranks : ranks) {
			Card* tmp = new Card(it_suits.first, it_ranks.first);
			deck.push_back(*tmp);
			//deck[(it_suits.first - 1) * ranks.size() + (it_ranks.first - 6)] = Card(it_suits.first, it_ranks.first);
		}
	}
}

void Deck::shuffling() {
	srand((unsigned int)time(NULL));
	std::vector<Card> tmp(this->deck.begin(), this->deck.end());
	std::random_shuffle(tmp.begin(), tmp.end());
	std::copy(tmp.begin(), tmp.end(), this->deck.begin());
}

std::vector<Card> Deck::getDeck() { return this->deck; }

Deck::~Deck() {}