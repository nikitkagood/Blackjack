cmake_minimum_required(VERSION 3.17)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "-O3")

add_subdirectory(deps/googletest)
#add_subdirectory(Calc)
add_subdirectory(Test_main)

#add_executable(Blackjack main.cpp "Blackjack.h" "IPlayer.h" "Dealer.h"  "AI_Player.h" "Blackjack.cpp" "IPlayer.cpp" )
add_executable(Blackjack main.cpp "Blackjack.h" "IPlayer.h" "Dealer.h"  "AI_Player.h" "Blackjack.cpp" "IPlayer.cpp" "Test_main/Test_m.cpp"  "AI_Player.cpp")

#target_link_libraries(Blackjack Calc)
target_link_libraries(Blackjack Test_m)
