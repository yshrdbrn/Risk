cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(part1 Part1/map.cpp Part1/map.h Part1/continent.cpp Part1/continent.h Part1/country.cpp Part1/country.h Part1/driver.cpp Part1/riskException.cpp Part1/riskException.h)

add_executable(part2 Part1/map.cpp Part1/map.h Part1/continent.cpp Part1/continent.h Part1/country.cpp Part1/country.h Part2/mapLoader.cpp Part2/mapLoader.h Part1/riskException.cpp Part1/riskException.h Part2/Driver2.cpp)

add_executable(part4 Part4/driver.cpp Part4/Player.cpp Part4/Player.h part_5/Deck.cpp part_5/Deck.h part_5/Hand.h part_5/Hand.cpp)