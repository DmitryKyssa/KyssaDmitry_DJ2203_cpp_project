#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

const std::unordered_map <int, std::string> suits{
	{1, "Diamonds"},
	{2, "Hearts"},
	{3, "Clubs"},
	{4, "Spades"}
};
const std::unordered_map <int, std::string> ranks{
	{6, "Six"},
	{7, "Seven"},
	{8, "Eight"},
	{9, "Nine"},
	{10, "Ten"},
	{11, "Jack"},
	{12, "Queen"},
	{13, "King"},
	{14, "Ace"},
};

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