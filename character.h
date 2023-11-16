#pragma once

#include <vector>
#include "card.h"

const int INITIAL_NUM_PLAYER_CARDS = 4;

/**
* \brief A class that represents an entity for Player and NPC classes
*/
/**
* Meta
* \brief Kyssa_Dmitry_DJ2203_cpp_project
* \author Kyssa Dmitry
* \date Sep-Dec 2023
*/
class Character {
public:
	/**
	* \brief Static method for providing singleton functionality
	* \return Pointer to variable Instance of class T
	*/
	template <typename T>
	static T* getInstance()
	{
		if (T::Instance == nullptr) {
			T::Instance = new T();
			return T::Instance;
		}
		else return T::Instance;
	}

	/**
	* \brief Method for printing T class objects
	*/
	template<typename T>
	void print();

	/**
	* \brief Method for counting score based on cards rank values
	* \return The sum of T class object cards rank values
	*/
	template<typename T>
	int countScore();

protected:
	/**
	* \brief Initial value for int countScore(). Becomes private field for derivative classes
	*/
	int score = 0;
};

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