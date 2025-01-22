//
// Created by Micha on 22/01/2025.
//

#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include "Potion.h"


class HealthPotion : public Potion {
    int m_healthRegeneration;
public:
    HealthPotion();
    void usePotion() override;
    void cancelBonus() override;
};



#endif //HEALTHPOTION_H
