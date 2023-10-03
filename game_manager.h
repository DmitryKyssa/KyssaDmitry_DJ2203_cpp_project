#pragma once

#include "card.h"
#include "character.h"
#include "player.h"
#include "npc.h"
#include "deck.h"
#include "windows.h"

void refreshScreen(Card& cOT, std::vector<Card>& uC) {
	system("cls");

	std::cout << "Player's cards:" << std::endl;
	Character::getInstance<Player>()->print <Player>();

	std::cout << std::endl;

	std::cout << "Card on table: ";
	std::cout << cOT << "Number of cards in deck: " << Character::getInstance<Deck>()->deck.size() << std::endl;

	std::cout << std::endl;

	std::cout << "NPC's cards:" << std::endl;
	Character::getInstance<NPC>()->print <NPC>();

	std::cout << std::endl;

	std::cout << "Cards in deck:" << std::endl;
	for (Card& it : Character::getInstance<Deck>()->deck) {
		std::cout << it;
	}

	std::cout << std::endl;

	std::cout << "Used cards:" << std::endl;
	for (Card& it : uC) {
		std::cout << it;
	}

	std::cout << std::endl;

	int counter = 0;

	if (Character::getInstance<Player>()->canMove) {
		Character::getInstance<Player>()->move(cOT, uC, counter);
		Character::getInstance<NPC>()->canMove = true;
	}

	uC.push_back(cOT);

	if (Character::getInstance<NPC>()->canMove) {
		Character::getInstance<NPC>()->move(cOT, counter);
		Character::getInstance<Player>()->canMove = true;
	}

	uC.push_back(cOT);

	Sleep(2000);
}