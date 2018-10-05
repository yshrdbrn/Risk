cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(part1 Part1/map.cpp Part1/map.h Part1/continent.cpp Part1/continent.h Part1/country.cpp Part1/country.h Part1/driver.cpp Part1/mapException.cpp Part1/mapException.h)