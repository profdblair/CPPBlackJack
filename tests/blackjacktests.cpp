/**
 * @file Player.cpp
 * @author Dave Blair (dblair@seafoamtechnologies.com)
 * @brief This is a Unit Test Fixture to the Card class
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024 Seafoam Technologies
 *
 */
#include <gtest/gtest.h>
#include "../src/Card.h"

// https://google.github.io/googletest/reference/assertions.html

/**
 * @brief Test parameterized constructor that creates a valid Card object.
 *      In this case, a card is created at the lowest valid suit integer
 *      and the highest valid value integer. Suit 1, Value 1
 */
TEST(CardTest, TestValidLowCard)
{
    Card card(1, 1, true);
    EXPECT_EQ(card.GetValue(), 11);
    EXPECT_EQ(card.ToString(), "ACE CLUBS");
}

/**
 * @brief Test parameterized constructor that creates a valid Card object.
 *      In this case, a card is created at the highest valid suit integer
 *      and the highest valid value integer. Suit 4, Value 13
 */
TEST(CardTest, TestValidHighCard)
{
    Card card(13, 4, true);
    EXPECT_EQ(card.GetValue(), 10);
    EXPECT_EQ(card.ToString(), "KING SPADES");
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 0 for suit. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, TestSuitLow)
{
    try
    {
        Card card(1, 0, true);
        FAIL(); /// If
    }
    catch (const std::exception &e)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 5 for suit. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, TestSuitHigh)
{
    try
    {
        Card card(1, 5, true);
        FAIL();
    }
    catch (const std::exception &e)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 0 for value. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, TestValueLow)
{
    try
    {
        Card card(0, 1, true);
        FAIL();
    }
    catch (const std::exception &e)
    {
        SUCCEED();
    }
}

/**
 * @brief Test parameterized constructor that creates an invalid Card object.
 *      In this case, a card is created using a 14 for value. It should
 *      throw an exception that if caught results in a Succeed.
 */
TEST(CardTest, TestValueHigh)
{
    try
    {
        Card card(14, 1, true);
        FAIL();
    }
    catch (const std::exception &e)
    {
        SUCCEED();
    }
}