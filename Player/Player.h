//
// Created by honza on 02.01.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>



enum PlayerType {
    ArcherType,
    WarriorType
};

class Player {

protected:

    int m_health;
    int m_defense;
    int m_strength;

    Player();

    public:

    static Player* createPlayer(PlayerType playerType);

};



#endif //PLAYER_H
