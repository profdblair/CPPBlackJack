#pragma once

#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Player
{
private:
    string _name;
    vector<Card> _hand;
    int _winThreshold;

    int calculateScore();

public:
    bool isBusted;

    Player(string name, int threshold);
    int GetThreshold();
    string GetName();
    void AddCard(Card card);
    string ShowHand();
    void EmptyHand();
    int CountCards();
    int Score();
    void FlipCard(int);
    void FlipAllCards(bool faceUp);
};