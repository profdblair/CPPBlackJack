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
#include <Player.h>

/**
 * @brief Construct a new Player:: Player object
 *
 * @param name
 * @param threshold
 */
Player::Player(string name, int threshold)
{
    _name = name;

    if (threshold < 1 || threshold > 21)
        throw runtime_error("Threshold must be between 1 and 21");

    _winThreshold = threshold;
    isBusted = false;
    isWinner = false;
}

/**
 * @brief
 *
 * @return int
 */
int Player::GetThreshold()
{
    return _winThreshold;
}

/**
 * @brief
 *
 * @return int
 */
int Player::Score()
{
    return calculateScore(_hand);
}

/**
 * @brief
 *
 * @param faceUp
 */
void Player::FlipAllCards(bool faceUp)
{
    for (int i = 0; i < _hand.size(); i++)
    {
        _hand[i].isFaceUp = faceUp;
    }
}

/**
 * @brief
 *
 * @param intCard
 */
void Player::FlipCard(int intCard)
{
    _hand[intCard].isFaceUp = true;
}

/**
 * @brief
 *
 * @param card
 */
void Player::AddCard(Card card)
{
    _hand.push_back(card);
}

/**
 * @brief
 *
 * @return string
 */
string Player::ShowHand()
{
    string temp = "";
    for (Card card : _hand)
    {
        temp += card.ToString() + " ";
    }
    return temp;
}

/**
 * @brief
 *
 */
void Player::EmptyHand()
{
    _hand.clear();
}

/**
 * @brief
 *
 * @return int
 */
int Player::CountCards()
{
    return _hand.size();
}

/**
 * @brief
 *
 * @return string
 */
string Player::GetName()
{
    return _name;
}

/**
 * @brief
 *
 * @return int
 */
int Player::calculateScore(vector<Card> hand)
{
    int score = 0;
    int numberOfAces = 0;

    for (Card card : hand)
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