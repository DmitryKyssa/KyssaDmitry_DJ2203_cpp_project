#pragma once

#include <vector>
#include "card.h"

const int INITIAL_NUM_PLAYER_CARDS = 4;

//TODO research expediency/utility of using an abstract or template class named Character
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
	for (Card& it : Character::getInstance<T>()->player_cards) {
		std::cout << it;
	}
}

template<typename T>
inline int Character::countScore() {
	for (Card& it : Character::getInstance<T>()->player_cards) {
		score += it.getRankValue();
	}
	return score;
}