//
// Created by honza on 23.01.2025.
//

#ifndef MONSTER_H
#define MONSTER_H
#include "../../Player/Player.h"
#include "../../Map/Room.h"
#include "../../Player/Archer.h"
#include "../../Player/Warrior.h"
#include "../../Options.h"
#include "../../Enums/PlayerType.h"


class Monster {

protected:

    int m_health;
    int m_strength;
    int m_defense;
    char m_symbol;

    public:

    Monster();

    virtual void attack(Player* player, Room* room) = 0;

    virtual void defend(Player* player) = 0;

    bool isItemAfterKill();



};



#endif //MONSTER_H
