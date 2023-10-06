#pragma once

#include <vector>
#include "card.h"

const int INITIAL_NUM_PLAYER_CARDS = 4;

class Character {
public:
	template <typename T>
	static T* getInstance();

	template<typename T>
	void print();

	//virtual void move(Card& cOT, int counter) = 0;

	virtual Card select(Card& cOT) = 0;

	virtual void draw() = 0;

	virtual void pass() = 0;

	virtual bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected) = 0;
};

template<typename T>
static inline T* Character::getInstance()
{
	if (T::Instance == nullptr) {
		T::Instance = new T();
		return T::Instance;
	}
	else return T::Instance;
}

template<typename T>
inline void Character::print()
{
	for (Card& it : Character::getInstance<T>()->player_cards) {
		std::cout << it;
	}
}