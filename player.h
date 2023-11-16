#pragma once

#include "character.h"

/**
* \brief A class that represents player. It is a child of class Character
*/
/**
* Meta
* \brief Kyssa_Dmitry_DJ2203_cpp_project
* \author Kyssa Dmitry
* \date Sep-Dec 2023
*/
class Player : public Character
{
public:
	/**
	* \brief Static pointer variable of class Player type to provide the functionality of singleton
	*/
	static Player* Instance;

	/**
	* \brief Default constructor
	*/
	Player();

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
	* \param[in] uC Vector of used cards
	* \param[in] numOfEntries Number of entries in method
	* \param[in] wasDrawn Flag of card drawing from #Deck::deck
	*/
	void move(Card& cOT, std::vector<Card> uC, int numOfEntries, bool wasDrawn);

	/**
	* \brief Method that determines card for moving
	* \param[in] cOT Current card on table
	* \param[in] uC Vector of used cards
	* \param[in] numOfEntries Number of entries in method
	* \return A card from #player_cards
	*/
	Card select(Card& cOT, std::vector<Card> uC, int numOfEntries);

	/**
	* \brief Method that add a card from #Deck::deck to #player_cards
	*/
	void draw();

	/**
	* \brief Method for refusing of move
	*/
	void pass();

	/**
	* \brief Method for control user input in #select(Card&, std::vector<Card>, int)
	* \param[in] _input Symbol entered from keyboard
	* \param[in] onTable Current card on table
	* \param[in] selected Reference to card from #player_cards by index #_input-1
	* \return True, if #selected complies with the rules of game.
	* False, if #selected do not complies with the rules of game or #_index is out of range for #player_cards
	*/
	bool checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected);

	/**
	* Destructor
	*/
	~Player();
};