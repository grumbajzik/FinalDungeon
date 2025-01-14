//
// Created by honza on 02.01.2025.
//

#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"


class Warrior : public Player{

    Position weaponPosition;

    public:

    Warrior(int health, int defence, int strength);

    void attack(Room* room, char input) override;

};



#endif //WARRIOR_H
