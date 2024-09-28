add_executable(
    blackjacktests
    blackjacktests.cpp
)

target_link_libraries(
  blackjacktests
  GTest::gtest_main
  cards
)

add_test(NAME cards COMMAND cards)