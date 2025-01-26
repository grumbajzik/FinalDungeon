//
// Created by Micha on 22/01/2025.
//

#ifndef POTION_H
#define POTION_H

#include "../Player/Player.h"


class Potion {

    public:

    static Potion *createPotion();
    virtual void usePotion(Player* player) = 0;
    virtual void cancelBonus() = 0;

private:

    int getRandomIndex();
};



#endif //POTION_H
