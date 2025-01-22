//
// Created by Micha on 22/01/2025.
//

#ifndef DEFENCEPOTION_H
#define DEFENCEPOTION_H
#include "Potion.h"


class DefencePotion : public Potion{
    int m_defenceBonus;
    int m_timeWhenBonusIsActive;
    public:
    DefencePotion();
    void usePotion() override;
    void cancelBonus() override;
};



#endif //DEFENCEPOTION_H
