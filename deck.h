#pragma once

#include <vector>
#include "card.h"

/**
* \brief A class that represents a deck of Card class objects
*/
/**
* Meta
* \brief Kyssa_Dmitry_DJ2203_cpp_project
* \author Kyssa Dmitry
* \date Sep-Dec 2023
*/
class Deck
{
public:
	/**
	* \brief Static pointer variable of class Deck type to provide the functionality of singleton
	*/
	static Deck* Instance;

	/**
	* \brief Default constructor for class Deck
	*/
	Deck();

	/**
	* \brief Vector of Card class objects. All cards in game
	*/
	std::vector<Card> deck;

	/**
	* \brief Method for changing the order of cards in the #deck
	*/
	void shuffling();

	/**
	* Destructor
	*/
	~Deck();
};