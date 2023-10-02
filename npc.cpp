#include "npc.h"

NPC::NPC()
{
	canMove = false;
	int currentSize = (int)Character::getInstance<Deck>()->deck.size();
	for (int i = (int)Character::getInstance<Deck>()->deck.size(); i > currentSize - INITIAL_NUM_PLAYER_CARDS; i--) {
		player_cards.push_back(Character::getInstance<Deck>()->deck.at(i - 1));
		Character::getInstance<Deck>()->deck.pop_back();
	}
}

NPC* NPC::Instance = nullptr;

void NPC::move(Card& cOT, int counter)
{
	cOT = select(cOT);

	if (cOT.getSuit() == "") {
		draw();
		move(cOT, counter);
	}

	canMove = false;
}

Card NPC::select(Card& cOT)
{
	Card empty;
	for (int i = 0; i < (int)player_cards.size(); i++) {
		if (player_cards.at(i).getSuit() == cOT.getSuit()
			|| player_cards.at(i).getRank() == cOT.getRank()
			|| player_cards.at(i).getRank() == "Jack") {
			Card tmp = player_cards.at(i);
			player_cards.erase(player_cards.begin() + i);
			return tmp;
		}
	}
	return empty;
}

//TODO after draw player can or select, or pass
void NPC::draw()
{
	player_cards.push_back(Character::getInstance<Deck>()->deck.back());
	Character::getInstance<Deck>()->deck.pop_back();
}

void NPC::pass()
{
	canMove = false;
}

bool NPC::checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected)
{
	return false;
}

NPC::~NPC()
{
}