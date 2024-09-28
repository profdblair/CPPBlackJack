# create a link library out of all the classes
add_library(cards STATIC 
    Card.cpp 
    Deck.cpp 
    Player.cpp)

target_include_directories(cards PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")