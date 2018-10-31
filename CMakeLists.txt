cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

set(MAP Model/Map/map.cpp Model/Map/map.h Model/Map/continent.cpp Model/Map/continent.h Model/Map/country.cpp Model/Map/country.h Model/Map/riskException.cpp Model/Map/riskException.h)
set(MAPLOADER Model/Maploader/mapLoader.cpp Model/Maploader/mapLoader.h)
set(PLAYER Model/Player/Player.cpp Model/Player/Player.h)
set(DICE Model/Dice/Dice_Roll.cpp Model/Dice/Dice_Roll.h)
set(CARDS Model/Cards/Deck.h Model/Cards/Deck.cpp Model/Cards/Hand.cpp Model/Cards/Hand.h)

set(MODEL ${MAP} ${MAPLOADER} ${PLAYER} ${DICE} ${CARDS})

add_executable(part1 Model/Map/driver.cpp ${MAP})

add_executable(part2 Model/Maploader/Driver2.cpp ${MAP} ${MAPLOADER})

add_executable(part3 Model/Dice/Driver.cpp ${DICE})

add_executable(part4 Model/Player/driver.cpp Model/Map/country.h Model/Map/country.cpp ${PLAYER} ${CARDS} ${DICE})

add_executable(part5 Model/Cards/main.cpp ${CARDS})

add_executable(a2_part1 Controller/GameEngine.cpp Controller/GameEngine.h View/GameSetupView.cpp View/GameSetupView.h Controller/DriverA2Part1.cpp ${MODEL})

add_executable(a2_part3 Controller/GameEngine.cpp Controller/GameEngine.h View/GameSetupView.cpp View/GameSetupView.h ${MODEL} Controller/DriverA2Part3.cpp View/GameFinishView.cpp View/GameFinishView.h)