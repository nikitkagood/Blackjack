cmake_minimum_required(VERSION 3.17)
project(test_project)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Calc)
add_subdirectory(deps/googletest)

add_executable(test_project main.cpp)

target_link_libraries(test_project Calc)