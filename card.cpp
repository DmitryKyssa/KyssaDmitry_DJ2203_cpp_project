#include "card.h"

Card::Card() {
	suitValue = 0;
	rankValue = 0;
}

Card::Card(int _suit, int _rank) {
	suitValue = _suit;
	rankValue = _rank;

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
	this->rankValue = other.rankValue;
	this->suitValue = other.suitValue;
	return *this;
}

Card::Card(const Card& copy)
{
	this->rank = copy.rank;
	this->suit = copy.suit;
	this->rankValue = copy.rankValue;
	this->suitValue = copy.suitValue;
}

const std::string& Card::getSuit() { return this->suit; }

const std::string& Card::getRank() { return this->rank; }

const int& Card::getRankValue() { return this->rankValue; }

std::ostream& operator<<(std::ostream& out, Card& card) {
	return out << card.getRank() << " " << card.getSuit() << std::endl;
}

std::istream& operator>>(std::istream& in, Card& card)
{
	std::cout << "Rank: ";
	in >> card.rank;
	std::cout << "Suit: ";
	in >> card.suit;

	for (auto& it_suits : suits) {
		if (it_suits.second == card.suit) {
			card.suitValue = it_suits.first;
		}
	}

	for (auto& it_ranks : ranks) {
		if (it_ranks.second == card.rank) {
			card.rankValue = it_ranks.first;
		}
	}

	return in;
}

Card::~Card() {}