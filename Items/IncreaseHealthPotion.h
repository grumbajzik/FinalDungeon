//
// Created by Micha on 22/01/2025.
//

#ifndef INCREASEHEALTHPOTION_H
#define INCREASEHEALTHPOTION_H
#include "Potion.h"


class IncreaseHealthPotion : public Potion {
    int m_healthIncrease;
    public:
    IncreaseHealthPotion();
    void usePotion() override;
    void cancelBonus() override;
};



#endif //INCREASEHEALTHPOTION_H
