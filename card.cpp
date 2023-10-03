#include "card.h"

Card::Card() {}

Card::Card(int _suit, int _rank) {
	this->suit = allSuits[_suit];
	this->rank = allRanks[_rank];
}

std::string Card::getSuit() { return this->suit; }

std::string Card::getRank() { return this->rank; }

std::ostream& operator<<(std::ostream& out, Card& card) {
	return out << card.getRank() << " " << card.getSuit() << std::endl;
}

Card::~Card() {}