cmake_minimum_required(VERSION 3.23)
project(Dungeon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dungeon main.cpp Game.cpp Game.h Menu/Button.cpp Menu/Button.h Menu/Menu.cpp Menu/Menu.h Options.cpp Options.h Map/Tyle.cpp Map/Tyle.h
        Menu/StartGameButton.cpp
        Menu/StartGameButton.h
        Menu/EditPlayerSkin.cpp
        Menu/EditPlayerSkin.h
        Menu/ExitGame.cpp
        Menu/ExitGame.h
        Player/Player.cpp
        Player/Player.h
        Player/Archer.cpp
        Player/Archer.h
        Player/Warrior.cpp
        Player/Warrior.h)
