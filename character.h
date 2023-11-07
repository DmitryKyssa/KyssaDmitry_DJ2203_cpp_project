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

	template<typename T>
	int countScore();

protected:
	int score = 0;
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
	for (size_t i = 0; i < Character::getInstance<T>()->player_cards.size(); i++) {
		std::cout << i + 1 << ") " << Character::getInstance<T>()->player_cards.at(i);
	}
}

template<typename T>
inline int Character::countScore() {
	for (Card& it : Character::getInstance<T>()->player_cards) {
		score += it.getRankValue();
	}
	return score;
}