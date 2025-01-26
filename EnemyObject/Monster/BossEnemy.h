//
// Created by honza on 26.01.2025.
//

#ifndef BOSSENEMY_H
#define BOSSENEMY_H
#include "Monster.h"


class BossEnemy : public Monster{

    Position BossPosition;

    public:

    BossEnemy();

    void mekaBossInRoom(Room* room);

    void attackDiagonally(Room* room);
    void attackHorizontally(Room* room);

    void attack(Player *player, Room *room) override;

    void defend(Player *player) override;

    void monsterDied();

};



#endif //BOSSENEMY_H
