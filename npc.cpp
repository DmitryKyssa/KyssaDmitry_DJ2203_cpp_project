#include "npc.h"

NPC::NPC()
{
}

NPC* NPC::Instance = nullptr;

void NPC::move(Card& cOT)
{
}

Card NPC::select(Card& cOT)
{
	return Card();
}

void NPC::draw()
{
}

void NPC::pass()
{
}

bool NPC::checkIfRangeIsCorrect(int _input, Card& onTable, Card& selected)
{
	return false;
}

NPC::~NPC()
{
}