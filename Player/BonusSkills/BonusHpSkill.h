//
// Created by honza on 21.01.2025.
//

#ifndef BONUSHPSKILL_H
#define BONUSHPSKILL_H
#include "Skills.h"


class BonusHpSkill : public Skills{

    int m_bonusHp;

    public:

    BonusHpSkill();

    void learnSkill(Player *player) override;
};



#endif //BONUSHPSKILL_H
