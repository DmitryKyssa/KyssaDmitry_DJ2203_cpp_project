#pragma once

#include "card.h"
#include "character.h"
#include "player.h"
#include "npc.h"
#include "deck.h"
#include "windows.h"

/**
* \brief Method for adding card(s) from #Deck::deck to #Player::player_cards or NPC::player_cards
* \param[in] numOfTakenCards Number of cards for taking
* \param[in] Type Pointer to class owning #Player::player_cards or NPC::player_cards
*/
template<typename T>
void takeCards(unsigned int numOfTakenCards, T* Type) {
	for (unsigned int i = 0; i < numOfTakenCards; i++) {
		Card tmp = Character::getInstance<Deck>()->deck.back();
		Character::getInstance<T>()->player_cards.push_back(tmp);
	}
}

/**
* \brief Method that defines special cards effect
* \param[in] cOT Current card on table
* \param[in] Type Pointer to class owning #Player::player_cards or NPC::player_cards
*/
template<typename T>
void cardsEffects(Card& cOT, T* Type) {
	if (cOT.getRank() == "Six") {
		takeCards<T>(1u, Type);
		return;
	}
	if (cOT.getRank() == "Seven") {
		takeCards<T>(2u, Type);
		return;
	}
	if (cOT.getRank() == "Nine" && cOT.getSuit() == "Diamonds") {
		takeCards<T>(5u, Type);
		return;
	}
}

/**
* \brief Method for updating console 
* \param[in] cOT Current card on table
* \param[in] uC Vector of used cards
* \param[in] wasDrawn Flag of card drawing from #Deck::deck
*/
inline void refreshScreen(Card& cOT, std::vector<Card>& uC, bool wasDrawn) {
	system("cls");

	std::cout << "Player's cards:" << std::endl;
	Player::getInstance<Player>()->print<Player>();

	std::cout << std::endl;

	std::cout << "Card on table: ";
	std::cout << cOT << "Number of cards in deck: " << Character::getInstance<Deck>()->deck.size() << std::endl;

	std::cout << std::endl;

	std::cout << "NPC's cards:" << std::endl;
	NPC::getInstance<NPC>()->print<NPC>();

	std::cout << std::endl;

	/*std::cout << "Cards in deck:" << std::endl;
	for (Card& it : Character::getInstance<Deck>()->deck) {
		std::cout << it;
	}*/

	std::cout << std::endl;

	std::cout << "Used cards:" << std::endl;
	for (Card& it : uC) {
		std::cout << it;
	}

	std::cout << std::endl;

	int playerCounter = 0;
	bool playerDrewCard = wasDrawn;

	if (Player::getInstance<Player>()->canMove) {
		Player::getInstance<Player>()->move(cOT, uC, playerCounter, playerDrewCard);
		NPC::getInstance<NPC>()->canMove = true;
	}

	uC.push_back(cOT);

	cardsEffects<NPC>(cOT, NPC::getInstance<NPC>());

	int npcCounter = 0;

	if (NPC::getInstance<NPC>()->canMove) {
		NPC::getInstance<NPC>()->move(cOT, npcCounter);
		Player::getInstance<Player>()->canMove = true;
	}

	uC.push_back(cOT);

	cardsEffects<Player>(cOT, Player::getInstance<Player>());

	Sleep(2000);
}