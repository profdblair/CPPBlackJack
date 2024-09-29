# CPP Blackjack Game

## Specifications

The Blackjack application will start by asking the application user how many players are playing the game simulation. Then the application will ask for the first name of all the players. There is no limit to how many player that will play the game. After enter names for all players, the application will play a game simulation for every player. Each player will start with 2 cards, then one at a time, each player will calculate their hand value. Then take another card and recalculate their had value until their hand value is greater than or equal to the threshold. After all players have completed their turns, all players score will be evaluated. They will either have "busted" (gone over 21), or have a score that is compared to all other scores and ranked accordingly. A tie does not matter which player is ranked above another. After all calculations present the game results in a user friendly way (see image).

![game screenshot](blackjackresults.png)

## UML

![uml screenshot](uml-class-diag.png)u

## Constraints

The developers are required to use the following tools:

### Application Tools

-   cmake/make
-   project folders
    -   app - main game
    -   inc - h & hpp
    -   src - cpp
    -   tests - googletest
    -   docs - Doxygen

## Algorithm Considerations

1. How will you calculate a players hand if an Ace, or even several Aces, can be a 1 or 11, depending on if it helps the user's score?

2. How will the game decide on if a player, or many players, will take another card or not if the game runs without user input?

3. How will the application decide who wins the game, who ties, who is busted?

4. How many player can there be?

## Compilation

-   This project uses cmake to compile to blackjack and blackjacktests executables
-   C++ 14 is required, CMake 3.14 is required.
-   To compile, cd to the main directory where the root CMakeLists.txt document is
-   cmake -S . -B build
-   cmake --build build
-   The game application will be in the build/app folder
-   The test fixture will be in the build folder

## Style Guide

-   All private class properties begin with an underscore and uses camel-case
-   All public class properties begin with an uppercase letter
-   All private class functions begin with a lowercase letter
-   All public class functions begin with an uppercase letter
-   boolean variables begin with "is"
-   Any const variables are all uppercase with an underscore between works
-   Any public functions begin with an uppercase letter
