//
// Created by honza on 03.01.2025.
//

#ifndef CLOSECOMBATENEMY_H
#define CLOSECOMBATENEMY_H
#include <iostream>
#include "../../Player/Player.h"
#include "../../Map/Room.h"

struct CloseClombatEnemyPosition {
    int x;
    int y;
};



class CloseCombatEnemy {

    protected:

    int m_health;
    int m_strength;
    int m_defense;
    char m_symbol;
    CloseClombatEnemyPosition closeCombatPosition;

    public:

    CloseCombatEnemy();

    void makeMonsterInRoom(Room* room);

    void attack(Player* player,Room* room);


};



#endif //CLOSECOMBATENEMY_H
