//
// Created by honza on 21.01.2025.
//

#include "BonusHpSkill.h"

BonusHpSkill::BonusHpSkill() {
    m_bonusHp = 100;
}

void BonusHpSkill::learnSkill(Player *player) {
    player->setMaxHealth(player->getMaxHealth()+m_bonusHp);
    if (player->getHealth()+100 <= player->getMaxHealth()) {
        player->setHealth(player->getHealth()+100);
    }else {
        player->setHealth(player->getMaxHealth());
    }
}
