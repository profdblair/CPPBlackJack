/**
 * @file Deck.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

/**
 * @brief
 *
 */
class Deck
{
private:
    /// @brief
    vector<Card> deck;

    /**
     * @brief
     *
     */
    void buildDeck();

    /**
     * @brief
     *
     */
    void shuffleDeck();

public:
    /**
     * @brief Construct a new Deck object
     *
     */
    Deck(bool);

    /**
     * @brief
     *
     * @return Card
     */
    Card Deal();

    /**
     * @brief
     *
     * @return string
     */
    string ToString();

    /**
     * @brief
     *
     * @return int
     */
    int CardsInDeck();
};