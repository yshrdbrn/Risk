cmake_minimum_required(VERSION 3.8)
project(riskGame)

set(CMAKE_CXX_STANDARD 14)

set(MAP Model/Map/map.cpp Model/Map/map.h Model/Map/continent.cpp Model/Map/continent.h Model/Map/country.cpp Model/Map/country.h Model/Map/riskException.cpp Model/Map/riskException.h)
set(MAPLOADER Model/Maploader/mapLoader.cpp Model/Maploader/mapLoader.h)
set(PLAYER Model/Player/Player.cpp Model/Player/Player.h Model/Player/Strategy.h Model/Player/HumanStrategy.cpp Model/Player/HumanStrategy.h Model/Player/AggressiveComputerStrategy.cpp Model/Player/AggressiveComputerStrategy.h Model/Player/BenevolentComputerStrategy.cpp Model/Player/BenevolentComputerStrategy.h Model/Player/Strategy.cpp Model/Player/RandomComputerStrategy.cpp Model/Player/RandomComputerStrategy.h)
set(DICE Model/Dice/Dice_Roll.cpp Model/Dice/Dice_Roll.h)
set(CARDS Model/Cards/Deck.h Model/Cards/Deck.cpp Model/Cards/Hand.cpp Model/Cards/Hand.h)

set(MODEL ${MAP} ${MAPLOADER} ${PLAYER} ${DICE} ${CARDS})
set(VIEW View/GameSetupView.cpp View/GameSetupView.h View/GameFinishView.cpp View/GameFinishView.h View/StatisticsObserver.cpp View/StatisticsObserver.h View/Observer.h View/PhaseObserver.cpp View/PhaseObserver.h)
set(CONTROLLER Controller/GameEngine.cpp Controller/GameEngine.h Controller/start_up_phase/startup.cpp Controller/start_up_phase/startup.h Controller/State.cpp Controller/State.h Controller/Observable.cpp Controller/Observable.h)
set(STARTUP Controller/start_up_phase/startup.cpp Controller/start_up_phase/startup.h)

add_executable(main Controller/DriverA2Part3.cpp ${MODEL} ${VIEW} ${CONTROLLER})

