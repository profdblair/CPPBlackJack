/**
 * @file Deck.cpp
 * @author your name (dblair@seafoamtechnologies.com)
 * @brief
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024 Seafoam Technologies
 *
 */
#include <iostream>
#include <Deck.h>

/**
 * @brief Parameterized constructor that, when true, creates and shuffles
 *      52 Cards, when false creates 52 Cards in a vector but does not shuffle them.
 *
 * @param shuffle
 */
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

/**
 * @brief
 *
 */
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

/**
 * @brief
 *
 */
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

/**
 * @brief
 *
 * @return int
 */
int Deck::CardsInDeck()
{
    return deck.size();
}

/**
 * @brief
 *
 * @return Card
 */
Card Deck::Deal()
{
    Card card = deck[0];
    deck.erase(deck.begin());
    return card;
}

/**
 * @brief
 *
 * @return string
 */
string Deck::ToString()
{
    string temp = "";
    for (Card card : deck)
    {
        temp += card.ToString() + "\n";
    }
    return temp;
}