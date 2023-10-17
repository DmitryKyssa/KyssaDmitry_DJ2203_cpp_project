#include <vector>
#include "game_manager.h"

Player::Player()
{
	canMove = true;
	int currentSize = (int)Character::getInstance<Deck>()->deck.size();
	for (int i = (int)Character::getInstance<Deck>()->deck.size(); i > currentSize - INITIAL_NUM_PLAYER_CARDS; i--) {
		player_cards.push_back(Character::getInstance<Deck>()->deck.at(i - 1));
		Character::getInstance<Deck>()->deck.pop_back();
	}
}

Player* Player::Instance = nullptr;

//TODO after draw player can or select, or pass
//TODO push back selected cards to used cards
void Player::move(Card& cOT, std::vector<Card> uC, int numOfEntries)
{
	int choice = 1;
	if (cOT.getRank() == "Eight") {
		do
		{
			std::cout << "\nChoose an option:\n"
				<< "1) Make a move\n"
				<< "2) Draw\n"
				<< "Enter 1 or 2: " << std::endl;
			std::cin >> choice;
		} while (!(choice >= 1 && choice <= 2));
	}
	else if (cOT.getRank() != "Eight" && numOfEntries == 0) {
		do
		{
			std::cout << "\nChoose an option:\n"
				<< "1) Make a move\n"
				<< "2) Draw\n"
				<< "3) Pass\n"
				<< "Enter 1, 2 or 3: " << std::endl;
			std::cin >> choice;
		} while (!(choice >= 1 && choice <= 3));
	}
	else if (cOT.getRank() != "Eight" && numOfEntries > 0) {
		canMove = false;
		return;
	}

	switch (choice)
	{
	case 1:
		cOT = select(cOT, uC, numOfEntries);
		numOfEntries++;
		move(cOT, uC, numOfEntries);
		canMove = false;
		break;
	case 2:
		draw();
		refreshScreen(cOT, uC);
		//move(cOT, numOfEntries);
		break;
	case 3:
		pass();
		break;
	}
}

Card Player::select(Card& cOT, std::vector<Card> uC, int numOfEntries)
{
	int input = 1;
	Card tmp;
	do
	{
		std::cout << "Please, select a card" << std::endl;
		std::cout << "Enter a number from 1 (first card) to " << player_cards.size() << " (last card)." << "Or 'D' to draw a card." << std::endl;
		std::cin >> input;

		if (input == 'D' || input == 'd') {
			draw();
			move(cOT, uC, numOfEntries++);
		}

		tmp = player_cards.at(input - 1);
	} while (!checkIfRangeIsCorrect(input, cOT, tmp));

	player_cards.erase(player_cards.begin() + input - 1);
	return tmp;
}

void Player::draw()
{
	player_cards.push_back(Character::getInstance<Deck>()->deck.back());
	Character::getInstance<Deck>()->deck.pop_back();
}

void Player::pass()
{
	canMove = false;
	return;
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

int Player::countScore() {
	for (Card& it : Character::getInstance<Player>()->player_cards) {
		score += it.getRankValue();
	}
	return score;
}

Player::~Player()
{
}