/**
 * @file utils.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <Card.h>
#include <Deck.h>
#include <Player.h>

namespace chants
{

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

    void SortPlayers(vector<Player> &players)
    {
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
    }

    void EnterPlayers(vector<Player> &players, int threshold)
    {
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
                cout << "Name for player number " << i + 1 << ": ";
                // cin.ignore();
                // getline(cin, strInput);
                cin >> strInput;
                players.push_back(Player(strInput, threshold));
            }
            Done = true;
        }
    }

    void PlayBlackJack(vector<Player> &players, Deck &deck)
    {
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
                    try
                    {
                        players[i].AddCard(deck.Deal());
                    }
                    catch (runtime_error e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }
                else
                {
                    if (players[i].Score() > 21)
                        players[i].isBusted = true;
                    // cout << players[i].GetName() << ": " << players[i].GetName() << " final score: " << players[i].Score() << endl;
                    players[i].FlipAllCards(true);
                    // cout << players[i].ShowHand() << endl;
                    break;
                }
            }
        }
    }
    void DetermineOutcomeOfGame(vector<Player> &players)
    {
        // int topScore = 0;
        bool busted = false;

        cout << "\n\n";
        cout << setw(10) << right << "Player" << setw(10) << right << "Score" << right << setw(10) << "Results" << " " << left << setw(30) << "Hand" << endl;
        cout << setw(10) << right << "------" << setw(10) << right << "-----" << right << setw(10) << "-------" << " " << left << setw(30) << "------------------------------" << endl;
        for (int i = 0; i < players.size(); i++)
        {
            if (players[i].isBusted)
            {
                busted = true;
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "BUSTED" << setw(1) << "" << left << setw(30) << players[i].ShowHand() << endl;
            }
            else if (players[i].isWinner)
            {
                busted = true;
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "WINNER" << setw(1) << "" << left << setw(30) << players[i].ShowHand() << endl;
            }
            else
            {
                cout << setw(10) << right << players[i].GetName() << setw(10) << right << players[i].Score()
                     << setw(10) << "" << setw(1) << "" << setw(30) << left << players[i].ShowHand() << endl;
            }
        }

        cout << "\n\n";
    }
}