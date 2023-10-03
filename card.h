#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

const std::string allSuits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};

const std::string allRanks[9] = { "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

class Card
{
private:
	std::string suit;
	std::string rank;
public:
	Card();

	Card(int _suit, int _rank);

	std::string getSuit();
	std::string getRank();

	friend std::ostream& operator<<(std::ostream& out, Card& card);

	~Card();
};