//
// Created by honza on 03.01.2025.
//

#ifndef ARTILLERYMONSTER_H
#define ARTILLERYMONSTER_H
#include <iostream>
#include "../../Map/Room.h"
#include "../../Player/Player.h"
#include "../../Player/Archer.h"
#include "../../Player/Warrior.h"
#include "../../Options.h"
#include "../../Enums/PlayerType.h"

struct ArtilleryPosition {
    int x;
    int y;
};


class ArtilleryMonster {

protected:

    int m_health;
    int m_strength;
    int m_defense;
    Room* m_room;
    char m_artillerySign;
    ArtilleryPosition artilleryPosition;
    ArtilleryPosition attackingPosition;
    char m_artilleryAttackTile;
    std::time_t m_lastAttack;

    public:

    ArtilleryMonster();

    void makeMonsterInRoom(Room* room);

    void attack(Player* player,Room* room);

    void defend(Player* player);

    void monsterDied();

    void threadAttack(Player *player, Room *room, int healthAfterDmg);
};



#endif //ARTILLERYMONSTER_H
