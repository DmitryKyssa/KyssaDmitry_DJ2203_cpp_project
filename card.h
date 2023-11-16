#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

/**
* \brief An unordered map that contains suits' names
*/
const std::unordered_map <int, std::string> suits{
	{1, "Diamonds"},
	{2, "Hearts"},
	{3, "Clubs"},
	{4, "Spades"}
};

/**
* \brief An unordered map that contains ranks' names and values
*/
const std::unordered_map <int, std::string> ranks{
	{6, "Six"},
	{7, "Seven"},
	{8, "Eight"},
	{9, "Nine"},
	{10, "Ten"},
	{2, "Jack"},
	{3, "Queen"},
	{4, "King"},
	{11, "Ace"},
};

/**
* \brief A class that represents a game card
*/
/**
* Meta
* \brief Kyssa_Dmitry_DJ2203_cpp_project
* \author Kyssa Dmitry
* \date Sep-Dec 2023
*/

class Card
{
private:
	std::string suit; 
	std::string rank;
	int suitValue;
	int rankValue;
public:
	/**
	* \brief Default constructor for class Card
	*/
	Card();

	/**
	* \brief Constructor with parameters for class Card
	* \param[in] _suit The suit of card
	* \param[in] _rank The rank of card
	*/
	Card(int _suit, int _rank);

	/**
	* \brief Copy constructor for class Card
	* \param[in] copy The suit of card
	*/
	Card(const Card& copy);

	/**
	* \brief operator= overload
	* \param[in] other Object for assignment (right operand)
 	* \return Pointer to this object (left operand)
	*/
	Card operator=(const Card& other);

	/**
	* \brief Getter for private variable
	* \return suit
	*/
	const std::string& getSuit();

	/**
	* \brief Getter for private variable
	* \return rank
	*/
	const std::string& getRank();

	/**
	* \brief Getter for private variable
	* \return suitValue
	*/
	const int& getSuitValue();

	/**
	* \brief Getter for private variable
	* \return rankValue
	*/
	const int& getRankValue();

	/**
	* \brief Friend overload for operator<<
	* \param[in] card Reference to object of class Card
	* \param[in, out] out Output stream
	*/
	friend std::ostream& operator<<(std::ostream& out, Card& card);

	/**
	* \brief Friend overload for operator>>
	* \param[in] card Reference to object of class Card
	* \param[in, out] in Input stream
	*/
	friend std::istream& operator>>(std::istream& in, Card& card);

	/**
	* \brief Destructor of class Card
	*/
	~Card();
};

/**
* \fn int operator==(Card left, Card right)
* \brief Overload of operator==
* \param[in] left Left operand for comparison
* \param[in] right Right operand for comparison
* \return Integer value:
* 0 if left and right have same #getRankValue()
* 1 if left rankValue is greater then right
*/
inline int operator==(Card left, Card right) {
	if (left.getRankValue() - right.getRankValue() > 0) {
		return 1;
	}
	else if (left.getRankValue() - right.getRankValue() < 0) {
		return -1;
	}
	else return 0;
}