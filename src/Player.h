/**
 * @file Player.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <vector>
#include <string>
#include "Card.h"

using namespace std;

/**
 * @brief
 *
 */
class Player
{
private:
    /// @brief
    string _name;
    /// @brief
    vector<Card> _hand;
    /// @brief
    int _winThreshold;

public:
    /// @brief
    bool isBusted;

    /// @brief
    bool isWinner;

    /**
     * @brief
     *
     * @return int
     */
    int calculateScore(vector<Card>);

    /**
     * @brief Construct a new Player object
     *
     * @param name
     * @param threshold
     */
    Player(string name, int threshold);

    /**
     * @brief Get the Threshold object
     *
     * @return int
     */
    int GetThreshold();

    /**
     * @brief Get the Name object
     *
     * @return string
     */
    string GetName();

    /**
     * @brief
     *
     * @param card
     */
    void AddCard(Card card);

    /**
     * @brief
     *
     * @return string
     */
    string ShowHand();

    /**
     * @brief
     *
     */
    void EmptyHand();

    /**
     * @brief
     *
     * @return int
     */
    int CountCards();

    /**
     * @brief
     *
     * @return int
     */
    int Score();

    /**
     * @brief
     *
     */
    void FlipCard(int);

    /**
     * @brief
     *
     * @param faceUp
     */
    void FlipAllCards(bool faceUp);
};