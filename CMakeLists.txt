cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

set(MAP Model/Map/map.cpp Model/Map/map.h Model/Map/continent.cpp Model/Map/continent.h Model/Map/country.cpp Model/Map/country.h Model/Map/riskException.cpp Model/Map/riskException.h)
set(MAPLOADER Model/Maploader/mapLoader.cpp Model/Maploader/mapLoader.h)
set(PLAYER Model/Player/Player.cpp Model/Player/Player.h Model/Player/Strategy.h Model/Player/HumanStrategy.cpp Model/Player/HumanStrategy.h Model/Player/AggressiveComputerStrategy.cpp Model/Player/AggressiveComputerStrategy.h Model/Player/BenevolentComputerStrategy.cpp Model/Player/BenevolentComputerStrategy.h Model/Player/Strategy.cpp)
set(DICE Model/Dice/Dice_Roll.cpp Model/Dice/Dice_Roll.h)
set(CARDS Model/Cards/Deck.h Model/Cards/Deck.cpp Model/Cards/Hand.cpp Model/Cards/Hand.h)
set(GAMESTATE Model/GameState/Subject.h Model/GameState/Subject.cpp Model/GameState/PhaseState.h Model/GameState/PhaseState.cpp)

set(MODEL ${MAP} ${MAPLOADER} ${PLAYER} ${DICE} ${CARDS} ${GAMESTATE})
set(VIEW View/GameSetupView.cpp View/GameSetupView.h View/GameFinishView.cpp View/GameFinishView.h View/PhaseView.h View/PhaseView.cpp View/Observer.h)
set(CONTROLLER Controller/GameEngine.cpp Controller/GameEngine.h Controller/start_up_phase/startup.cpp Controller/start_up_phase/startup.h)
set(STARTUP Controller/start_up_phase/startup.cpp Controller/start_up_phase/startup.h)

add_executable(part4 Model/Player/driver.cpp ${PLAYER} ${CARDS} ${DICE} ${MAPLOADER} ${MAP})

add_executable(a2_part1 Controller/DriverA2Part1.cpp ${MODEL} ${VIEW} ${CONTROLLER})

add_executable(a2_part3 Controller/DriverA2Part3.cpp ${MODEL} ${VIEW} ${CONTROLLER})

add_executable(a3part1 ${MODEL} ${VIEW} ${CONTROLLER} Model/Player/Strategy.h Model/Player/HumanStrategy.cpp Model/Player/HumanStrategy.h)
