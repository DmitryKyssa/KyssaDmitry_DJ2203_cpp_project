#include "card.h"

Card::Card() {}

Card::Card(int _suit, int _rank) {
	/*this->suit = allSuits[_suit];
	this->rank = allRanks[_rank];*/
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

Card Card::operator=(const Card& other)
{
	this->suit = other.suit;
	this->rank = other.rank;
	return *this;
}

Card::Card(const Card& copy)
{
	this->rank = copy.rank;
	this->suit = copy.suit;
}

std::string Card::getSuit() { return this->suit; }

std::string Card::getRank() { return this->rank; }

std::ostream& operator<<(std::ostream& out, Card& card) {
	return out << card.getRank() << " " << card.getSuit() << std::endl;
}

std::istream& operator>>(std::istream& in, Card& card)
{
	std::cout << "Rank: ";
	in >> card.rank;
	std::cout << "Suit: ";
	in >> card.suit;

	return in;
}

int operator==(Card& left, Card& right) {
	if (left.getRank() == right.getRank()) {
		return 0;
	}
	else if (left.getRank() > right.getRank()) {
		return 1;
	}
	else return -1;
}

Card::~Card() {}