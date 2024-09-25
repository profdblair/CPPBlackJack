#include <iostream>
#include "Deck.h"

Deck::Deck(bool shuffle)
{
    if (shuffle)
    {
        buildDeck();
        shuffleDeck();
    }
    else
    {
        buildDeck();
    }
}

void Deck::buildDeck()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            Card card(j, i, false);
            deck.push_back(card);
        }
    }
}

void Deck::shuffleDeck()
{
    srand(time(nullptr));
    for (int i = 0; i < 10000; i++)
    {
        int index1 = rand() % 52;
        int index2 = rand() % 52;
        Card tempCard = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = tempCard;
    }
}

int Deck::CardsInDeck()
{
    return deck.size();
}

Card Deck::Deal()
{
    Card card = deck[0];
    deck.erase(deck.begin());
    return card;
}

string Deck::ToString()
{
    string temp = "";
    for (Card card : deck)
    {
        temp += card.ToString() + "\n";
    }
    return temp;
}