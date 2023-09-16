// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "GameBasicStructs.h"

int main()
{
    Card* card = new Card(1, 7);
    card->Print();

    return 0;
}
