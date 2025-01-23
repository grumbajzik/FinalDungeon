//
// Created by Micha on 22/01/2025.
//

#ifndef DAMAGEPOTION_H
#define DAMAGEPOTION_H
#include "Potion.h"


class DamagePotion : public Potion{
    int m_damageBonus;
    int m_timeWhenBonusIsActive;
public:
    DamagePotion();
    void usePotion() override;
    void cancelBonus() override;
};



#endif //DAMAGEPOTION_H
