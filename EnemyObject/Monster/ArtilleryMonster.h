//
// Created by honza on 03.01.2025.
//

#ifndef ARTILLERYMONSTER_H
#define ARTILLERYMONSTER_H
#include <iostream>
#include "../../Map/Room.h"
#include "../../Player/Player.h"

struct ArtilleryPosition {
    int x;
    int y;
};


class ArtilleryMonster {

protected:

    int m_health;
    int m_strength;
    int m_defense;
    char m_artillerySign;
    ArtilleryPosition artilleryPosition;
    ArtilleryPosition attackingPosition;
    char m_artilleryAttackTile;

    public:

    ArtilleryMonster();

    void makeMonsterInRoom(Room* room);

    void attack(Player* player,Room* room);

    void defend(Player* player);
};



#endif //ARTILLERYMONSTER_H
