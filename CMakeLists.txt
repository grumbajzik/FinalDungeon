cmake_minimum_required(VERSION 3.23)
project(Dungeon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dungeon main.cpp Game.cpp Game.h Menu/Button.cpp Menu/Button.h Menu/Menu.cpp Menu/Menu.h Options.cpp Options.h Map/Tyle.cpp Map/Tyle.h)
