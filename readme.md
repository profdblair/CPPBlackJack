# CPP Blackjack Game

## Application Tools

-   g++
-   cmake/make
-   googletest
-   Doxygen

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
