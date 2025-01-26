//
// Created by Micha on 22/01/2025.
//

#include "DamagePotion.h"

#include <thread>

DamagePotion::DamagePotion() {
    m_damageBonus = 20;
}

 void DamagePotion::usePotion() {
//     int DamageBeforeBuff = player->getStrength();
//     player->setStrength(DamageBeforeBuff + m_damageBonus);
//     std::thread cancelDamageBonusThread([this, player]() {
//             cancelBonus(player);
//         });
//     cancelDamageBonusThread.detach();
//
}
//
void DamagePotion::cancelBonus() {
//     std::this_thread::sleep_for(std::chrono::seconds(30));
//     player->setStrength(player->getStrength() - m_damageBonus);
}
