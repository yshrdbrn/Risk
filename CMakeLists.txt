cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(part1 Model/Map/map.cpp Model/Map/map.h Model/Map/continent.cpp Model/Map/continent.h Model/Map/country.cpp Model/Map/country.h Model/Map/driver.cpp Model/Map/riskException.cpp Model/Map/riskException.h)

add_executable(part2 Model/Map/map.cpp Model/Map/map.h Model/Map/continent.cpp Model/Map/continent.h Model/Map/country.cpp Model/Map/country.h Model/Maploader/mapLoader.cpp Model/Maploader/mapLoader.h Model/Map/riskException.cpp Model/Map/riskException.h Model/Maploader/Driver2.cpp)

add_executable(part3 Model/Dice/Dice_Roll.cpp Model/Dice/Dice_Roll.h Model/Dice/Driver.cpp)

add_executable(part4 Model/Player/driver.cpp Model/Player/Player.cpp Model/Player/Player.h Model/Cards/Deck.cpp Model/Cards/Deck.h Model/Cards/Hand.h Model/Cards/Hand.cpp Model/Map/country.h Model/Map/country.cpp Model/Dice/Dice_Roll.h Model/Dice/Dice_Roll.cpp)

add_executable(part5 Model/Cards/Deck.h Model/Cards/Deck.cpp Model/Cards/Hand.cpp Model/Cards/Hand.h Model/Cards/main.cpp)