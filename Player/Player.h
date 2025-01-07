//
// Created by honza on 02.01.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../Map/Tile.h"


enum PlayerType {
    ArcherType,
    WarriorType
};

class Player {

protected:

    int m_health;
    int m_defense;
    int m_strength;
    Tile* playerTile;

    Player();

    public:

    static Player* createPlayer(PlayerType playerType);

    //virtual void attack() = 0;

};



#endif //PLAYER_H
