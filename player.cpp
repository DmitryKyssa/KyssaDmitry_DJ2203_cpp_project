#include "player.h"
#include <vector>
#include "game_basic_structs.h"

Player::Player()
{
	for (int i = 0; i < INITIAL_NUM_PLAYER_CARDS; i++) {
		player_cards.push_back(Character::getInstance<Deck>()->deck.at(i));
		Character::getInstance<Deck>()->deck.pop_back();
	}
}

Player* Player::Instance = nullptr;

void Player::move(Card& cOT)
{
	int choice;
	if (cOT.getRank() == "Eight") {
		do
		{
			std::cout << "\nChoose an option:\n"
				<< "1) Make a move"
				<< "2) Draw"
				<< "Enter 1 or 2: " << std::endl;
			std::cin >> choice;
		} while (!(choice >= 1 && choice <= 2));
	}
	else {
		do
		{
			std::cout << "\nChoose an option:\n"
				<< "1) Make a move"
				<< "2) Draw"
				<< "3) Pass"
				<< "Enter 1, 2 or 3: " << std::endl;
			std::cin >> choice;
		} while (!(choice >= 1 && choice <= 3));
	}

	switch (choice)
	{
	case 1:
		cOT = select(cOT);
		break;
	case 2:
		draw();
		break;
	case 3:
		pass();
		break;
	}
}

Card Player::select(Card& cOT)
{
	int input;
	Card tmp;
	do
	{
		std::cout << "Please, select a card" << std::endl;
		std::cout << "Enter a number from 1 (first card) to " << player_cards.size() << " (last card):" << std::endl;
		std::cin >> input;
		tmp = player_cards.at(input - 1);
	} while (!checkIfRangeIsCorrect(input, cOT, tmp));

	player_cards.erase(player_cards.begin() + input - 1);
	return tmp;
}

void Player::draw()
{
}

void Player::pass()
{
}

bool Player::checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected)
{
	if (_input >= 1 && _input <= (int)player_cards.size()) {
		if (onTable.getRank() == selected.getRank()
			|| onTable.getSuit() == selected.getSuit()
			|| selected.getRank() == "Jack") {
			return true;
		}
		else {
			std::cout << "Card must be the suit " << onTable.getSuit() << " or rank "
				<< onTable.getRank() << " or a Jack!" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Incorrect input! Enter a number from 1 to " << player_cards.size() << std::endl;
		return false;
	}
}

Player::~Player()
{
}