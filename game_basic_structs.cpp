#include"game_basic_structs.h"

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

void Card::Print() {
	std::cout << this->suit << " " << this->rank << std::endl;
}

Card::~Card() {}