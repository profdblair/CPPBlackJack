/**
 * @file game.cpp
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
#include <utils.h>
#include <Card.h>

using namespace std;
using namespace chants;

int main(int argc, char **argv)
{
    // Default threshold if no argv
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
    EnterPlayers(players, threshold);
    PlayBlackJack(players, deck);
    SortPlayers(players);
    DetermineOutcomeOfGame(players);
}
