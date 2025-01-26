//
// Created by honza on 03.01.2025.
//

#ifndef ARTILLERYMONSTER_H
#define ARTILLERYMONSTER_H
#include <iostream>

#include "Monster.h"


struct ArtilleryPosition {
    int x;
    int y;
};


class ArtilleryMonster : public Monster {

protected:

    Room* m_room;
    ArtilleryPosition artilleryPosition;
    ArtilleryPosition attackingPosition;
    char m_artilleryAttackTile;
    std::time_t m_lastAttack;

    public:

    ArtilleryMonster();

    void makeMonsterInRoom(Room* room);

    void attack(Player* player,Room* room) override;

    void defend(Player* player) override;

    void monsterDied();

    void threadAttack(Player *player, Room *room, int healthAfterDmg);

    bool isItemAfterKill();
};



#endif //ARTILLERYMONSTER_H
