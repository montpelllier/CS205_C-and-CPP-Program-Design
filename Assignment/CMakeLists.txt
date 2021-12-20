cmake_minimum_required(VERSION 3.17)
project(Assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(a1 Assignment1.cpp)
add_executable(a2 Assignment2.cpp)
add_executable(a3 Assignment3.cpp utf8.h utf8.c)
add_executable(a4 Assignment4.cpp)
add_executable(a4q5 Assignment4_Q5.cpp)

add_executable(utf8 using_utf8_to_codepoint.c utf8.h utf8.c)