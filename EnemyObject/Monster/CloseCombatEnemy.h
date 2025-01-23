//
// Created by honza on 03.01.2025.
//

#ifndef CLOSECOMBATENEMY_H
#define CLOSECOMBATENEMY_H
#include <iostream>

#include "Monster.h"
#include "../../Player/Archer.h"
#include "../../Player/Warrior.h"
#include "../../Options.h"
#include "../../Enums/PlayerType.h"

struct CloseClombatEnemyPosition {
    int x;
    int y;
};

class CloseCombatEnemy : public Monster{

    protected:

    CloseClombatEnemyPosition closeCombatPosition;
    Tile* m_previousTile;
    std::time_t m_lastAttack;

    public:

    CloseCombatEnemy();

    void makeMonsterInRoom(Room* room);

    void attack(Player* player,Room* room) override;

    void defend(Player* player) override;

    void monsterDied();

    void ThreadAttack(Player *player, Room *room);
};



#endif //CLOSECOMBATENEMY_H
