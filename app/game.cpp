#include <iostream>
#include <vector>
#include "../src/Card.h"
#include "../src/Deck.h"
#include "../src/Player.h"
using namespace std;

bool comparator(Player &lhs, Player &rhs);
bool isANumber(string s);

int main(int argc, char **argv)
{
    int threshold = 17;
    if (argc == 2 && isANumber(argv[1]))
    {
        // cout << argv[1];
        string strThreshold = argv[1];
        threshold = stoi(strThreshold);
    }
    cout << "Threshold: " << threshold << endl;

    vector<Player> players;
    Deck deck(true);

    bool Done = false;
    string strInput;
    int input;
    while (!Done)
    {
        cout << "Number of players: ";
        cin >> strInput;
        input = stoi(strInput);
        for (int i = 0; i < input; i++)
        {
            cout << "Enter the name for your player number " << i + 1 << ": ";
            cin >> strInput;
            players.push_back(Player(strInput, threshold));
        }
        Done = true;
    }

    for (int i = 0; i < players.size(); i++)
    {
        //  play hand
        //  deal two cards
        players[i].AddCard(deck.Deal());
        players[i].AddCard(deck.Deal());

        while (true)
        {
            if (players[i].Score() < players[i].GetThreshold())
            {
                players[i].AddCard(deck.Deal());
            }
            else
            {
                if (players[i].Score() > 21)
                    players[i].isBusted = true;
                cout << players[i].GetName() << ": " << players[i].GetName() << " final score: " << players[i].Score() << endl;
                players[i].FlipAllCards(true);
                cout << players[i].ShowHand() << endl;
                break;
            }
        }
    }

    // pass function to sort
    sort(players.begin(), players.end(), &comparator);

    int highestScore = 0;
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].Score() <= 21)
        {
            if (players[i].Score() >= highestScore)
            {
                players[i].isWinner = true;
                highestScore = players[i].Score();
            }
        }
    }

    // int topScore = 0;
    bool busted = false;

    cout << "\nSorted scores:\n";
    for (int i = 0; i < players.size(); i++)
    {

        if (players[i].isBusted)
        {
            busted = true;
            cout << "Player " << players[i].GetName() << " final score: " << players[i].Score()
                 << " BUSTED" << endl;
        }
        else if (players[i].isWinner)
        {
            busted = true;
            cout << "Player " << players[i].GetName() << " final score: " << players[i].Score()
                 << " Winner" << endl;
        }
        else
        {
            cout << "Player " << players[i].GetName() << " final score: " << players[i].Score()
                 << endl;
        }
    }
}

// define the function:
bool comparator(Player &lhs, Player &rhs)
{
    return lhs.Score() > rhs.Score();
}

bool isANumber(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
