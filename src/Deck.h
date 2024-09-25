#pragma once

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
private:
    vector<Card> deck;

    void buildDeck();
    void shuffleDeck();

public:
    Deck(bool);
    Card Deal();
    string ToString();
    int CardsInDeck();
};