/**
 * @file Player.cpp
 * @author Dave Blair (dblair@seafoamtechnologies.com)
 * @brief Player class details
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024 Seafoam Technologies
 *
 */
#include "Player.h"

/**
 * @brief Construct a new Player:: Player object
 *
 * @param name
 * @param threshold
 */
Player::Player(string name, int threshold)
{
    _name = name;
    _winThreshold = threshold;
    isBusted = false;
}

int Player::GetThreshold()
{
    return _winThreshold;
}

int Player::Score()
{
    return calculateScore();
}

void Player::FlipAllCards(bool faceUp)
{
    for (int i = 0; i < _hand.size(); i++)
    {
        _hand[i].isFaceUp = faceUp;
    }
}

void Player::FlipCard(int intCard)
{
    _hand[intCard].isFaceUp = true;
}

int Player::calculateScore()
{
    int score = 0;
    int numberOfAces = 0;

    for (Card card : _hand)
    {
        int val = card.GetValue();
        if (val == 11)
        {
            numberOfAces++;
        }
        score += val;
    }

    if (score > 21)
    {
        while (true)
        {
            if (numberOfAces > 0)
            {
                score = score - 10;
                numberOfAces--;
            }
            else
                break;
        }
    }

    return score;
}

void Player::AddCard(Card card)
{
    _hand.push_back(card);
}

string Player::ShowHand()
{
    string temp = "";
    for (Card card : _hand)
    {
        temp += card.ToString() + "\n";
    }
    return temp;
}

void Player::EmptyHand()
{
    _hand.clear();
}

int Player::CountCards()
{
    return _hand.size();
}

string Player::GetName()
{
    return _name;
}