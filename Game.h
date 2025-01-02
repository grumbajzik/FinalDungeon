//
// Created by Admin on 27.12.2024.
//

#ifndef DUNGEON_GAME_H
#define DUNGEON_GAME_H
#include "Menu/Menu.h"
#include <conio.h>

#include "Player/Player.h"


class Game {
    static Menu* m_menu;
    static Player* m_player;
public:
    static PlayerType m_playerType;

    static void Run(int index);
};


#endif //DUNGEON_GAME_H
