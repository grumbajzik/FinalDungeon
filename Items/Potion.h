//
// Created by Micha on 22/01/2025.
//

#ifndef POTION_H
#define POTION_H

#include "../Player/Player.h"


class Potion {
    int m_index;
    Player* m_player;
    public:
    static Potion *createPotion(int index);
    virtual void usePotion() = 0;
    virtual void cancelBonus() = 0;
    int getRandomIndex();
};



#endif //POTION_H
