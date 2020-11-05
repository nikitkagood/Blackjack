cmake_minimum_required(VERSION 3.17)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Calc)
add_subdirectory(deps/googletest)

add_executable(Blackjack main.cpp "Blackjack.h" "Player.h" "Dealer.h" "HumanPlayer.h" "AI_Player.h")

target_link_libraries(Blackjack Calc)