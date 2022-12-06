cmake_minimum_required(VERSION 3.23)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode main.cpp Day1/Day1Code.cpp HelperClass.h HelperClass.cpp Day2/Day2.cpp Day3/Day3.cpp)
