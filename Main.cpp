// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "game_basic_structs.h"

int main()
{
    Card deck[36];

    //Creating deck of cards
    for (int i = 1; i <= 4; i++) {
        for (int j = 6; j <= 14; j++) {
            deck[(i - 1) * 9 + (j - 6)] = Card(i, j);
        }
    }

    //Print all cards name
    for (int i = 0; i < sizeof(deck) / sizeof(deck[0]); i++) {
        deck[i].Print();
    }

    return 0;
}
