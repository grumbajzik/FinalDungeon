//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_GAME_H
#define DUNGEON_GAME_H
#include "Menu/Menu.h"
#include <conio.h>



class Game {
    Menu* m_menu;
public:
    Game();
    void Run(int index);
};


#endif //DUNGEON_GAME_H
