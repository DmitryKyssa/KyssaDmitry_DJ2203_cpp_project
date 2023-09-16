#pragma once

#include<iostream>
#include"enum.h"

BETTER_ENUM(Suits, int, Diamonds = 1, Hearts = 2, Clubs = 3, Spades = 4);

enum Ranks
{
	Six = 6,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

class Card
{
private:
	std::string suit;
	std::string rank;
public:
	Card(int _suit, int _rank)
	{
		try
		{
			Suits suit = Suits::_from_integral(_suit);
			std::cout << suit;

			//this->suit = static_cast<>(getSuit);

		}
		catch (const std::exception&)
		{
			std::cout << "There is no such value!";
		}


		/*this->suit = ;
		this->rank = ;*/
	}

	void Print() {
		std::cout << "Suit:" << this->suit;
	}

	~Card();
};
