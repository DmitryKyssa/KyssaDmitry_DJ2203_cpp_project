#pragma once

#include "character.h"

/**
* \brief A class that represents NPC. It is a child of class Character
*/
/**
* Meta
* \brief Kyssa_Dmitry_DJ2203_cpp_project
* \author Kyssa Dmitry
* \date Sep-Dec 2023
*/
class NPC : public Character
{
public:
	/**
	* \brief Static pointer variable of class NPC type to provide the functionality of singleton
	*/
	static NPC* Instance;

	/**
	* \brief Default constructor
	*/
	NPC();

	/**
	* \brief Vector of Card class objects. Cards of Player object
	*/
	std::vector<Card> player_cards;

	/**
	* \brief Flag for detecting posibility to move
	*/
	bool canMove;

	/**
	* \brief Method that defines rules of a move
	* \param[in] cOT Current card on table
	* \param[in] counter Number of entries in method
	*/
	void move(Card& cOT, int counter);

	/**
	* \brief Method that determines card for moving
	* \param[in] cOT Current card on table
	* \return A card from #player_cards
	*/
	Card select(Card& cOT);

	/**
	* \brief Method that add a card from #Deck::deck to #player_cards
	*/
	void draw();

	/**
	* \brief Method for refusing of move
	*/
	void pass();

	/**
	* Destructor
	*/
	~NPC();
};