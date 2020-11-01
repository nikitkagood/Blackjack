project(Calc_Test)

add_executable(Calc_Test test_calc.cpp)

target_link_libraries(Calc_Test Calc gtest)

enable_testing()
add_test(NAME Calc_Test COMMAND Calc_Test)