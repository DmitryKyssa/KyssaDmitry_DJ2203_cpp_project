#include "operations_with_deck.h"

std::vector<Card> shuffling(std::vector<Card>& _deck) {
	srand(time(NULL));
	std::vector<Card> tmp(_deck.begin(), _deck.end());
	std::random_shuffle(tmp.begin(), tmp.end());
	std::copy(tmp.begin(), tmp.end(), _deck.begin());

	return _deck;
}