//
// Created by honza on 02.01.2025.
//

#ifndef ARCHER_H
#define ARCHER_H
#include "Player.h"




class Archer : public Player{

    Position bulletPosition;
    int m_attackRange;
    std::time_t m_lastAttack;
    public:

    Archer(int health, int defence, int strength);

    void attack(Room* room, char input) override;


};



#endif //ARCHER_H
