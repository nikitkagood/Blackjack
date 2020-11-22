project(Test_Main)

add_executable(Test_Main Test_main.cpp "../../Blackjack.h" "../../IPlayer.h" "../../Dealer.h"  "../../AI_Player.h" "../../Blackjack.cpp" "../../IPlayer.cpp" )

target_link_libraries(Test_Main Test_m gtest)

enable_testing()
add_test(NAME Test_Main COMMAND Test_Main)